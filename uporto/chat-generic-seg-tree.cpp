#include <iostream>
#include <vector>
#include <functional>
#include <limits>

template <typename T>
class SegmentTree {
private:
    std::vector<T> tree;
    int size;
    T neutral;
    std::function<T(T, T)> merge;

    // Construir a árvore a partir de um vetor inicial
    void build(const std::vector<T>& data, int pos, int start, int end) {
        if (start == end) {
            tree[pos] = data[start];
        } else {
            int middle = start + (end - start) / 2;
            build(data, pos * 2, start, middle);
            build(data, pos * 2 + 1, middle + 1, end);
            tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }

    // Atualizar o valor em um índice específico
    void update(int pos, int start, int end, int index, T value) {
        if (start == end) {
            tree[pos] = value;
        } else {
            int middle = start + (end - start) / 2;
            if (index <= middle) {
                update(pos * 2, start, middle, index, value);
            } else {
                update(pos * 2 + 1, middle + 1, end, index, value);
            }
            tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
        }
    }

    // Consultar o intervalo [left, right]
    T query(int pos, int start, int end, int left, int right) const {
        if (left > end || right < start) return neutral;
        if (start >= left && end <= right) return tree[pos];

        int middle = start + (end - start) / 2;
        T left_result = query(pos * 2, start, middle, left, right);
        T right_result = query(pos * 2 + 1, middle + 1, end, left, right);
        return merge(left_result, right_result);
    }

public:
    // Construtor para inicializar o Segment Tree
    SegmentTree(const std::vector<T>& data, T neutral, std::function<T(T, T)> merge)
        : size(data.size()), neutral(neutral), merge(merge) {
        tree.resize(size * 4); // Espaço suficiente para armazenar a árvore
        build(data, 1, 0, size - 1);
    }

    // Função de atualização
    void update(int index, T value) {
        update(1, 0, size - 1, index, value);
    }

    // Função de consulta
    T query(int left, int right) const {
        return query(1, 0, size - 1, left, right);
    }
};


#include <iostream>
#include <vector>
#include <limits>
#include <functional>

// Aqui está a classe SegmentTree - já definida anteriormente

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};

    // Exemplo 1: Soma de um intervalo
    SegmentTree<int> sumTree(
        data,
        0,  // Valor neutro para soma
        [](int a, int b) { return a + b; }  // Função de merge para soma
    );
    std::cout << "Soma do intervalo [1, 3]: " << sumTree.query(1, 3) << std::endl;
    sumTree.update(2, 10);  // Atualiza índice 2 para 10
    std::cout << "Soma do intervalo [1, 3] após atualização: " << sumTree.query(1, 3) << std::endl;

    // Exemplo 2: Mínimo de um intervalo
    SegmentTree<int> minTree(
        data,
        std::numeric_limits<int>::max(),  // Valor neutro para mínimo
        [](int a, int b) { return std::min(a, b); }  // Função de merge para mínimo
    );
    std::cout << "Mínimo do intervalo [1, 4]: " << minTree.query(1, 4) << std::endl;
    minTree.update(3, 2);  // Atualiza índice 3 para 2
    std::cout << "Mínimo do intervalo [1, 4] após atualização: " << minTree.query(1, 4) << std::endl;

    // Exemplo 3: Máximo de um intervalo
    SegmentTree<int> maxTree(
        data,
        std::numeric_limits<int>::min(),  // Valor neutro para máximo
        [](int a, int b) { return std::max(a, b); }  // Função de merge para máximo
    );
    std::cout << "Máximo do intervalo [2, 5]: " << maxTree.query(2, 5) << std::endl;
    maxTree.update(4, 20);  // Atualiza índice 4 para 20
    std::cout << "Máximo do intervalo [2, 5] após atualização: " << maxTree.query(2, 5) << std::endl;

    return 0;
}

