#include <iostream>
#include <fstream>
#include <random>
#include <unordered_set>

// Custom hash function for std::pair<int, int>
struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main() {
    // Parâmetros dados
    int v = 100;  // Número de vértices
    int t = 300;  // Número de trilhas
    int p = 30;   // Número de portais

    // Abrir arquivo para escrita
    std::ofstream file("grafo.txt");
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return 1;
    }

    // Configuração do gerador de números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> vertex_dis(0.0, 100.0);  // Coordenadas de vértices de 0 a 100

    // Gerar vértices
    for (int i = 0; i < v; ++i) {
        float x = vertex_dis(gen);
        float y = vertex_dis(gen);
        file << x << " " << y << "\n";
    }

    // Gerar trilhas
    std::uniform_int_distribution<int> vertex_dist(0, v - 1);  // Distribuição para vértices de 0 a v-1
    std::unordered_set<std::pair<int, int>, PairHash> edges;  // Usar PairHash como o hash

    while (edges.size() < t) {
        int u = vertex_dist(gen);
        int v = vertex_dist(gen);
        if (u != v) {
            edges.insert({std::min(u, v), std::max(u, v)});
        }
    }

    for (const auto& edge : edges) {
        file << edge.first << " " << edge.second << "\n";
    }

    // Gerar portais
    edges.clear();  // Limpar conjunto para reutilização

    while (edges.size() < p) {
        int u = vertex_dist(gen);
        int v = vertex_dist(gen);
        if (u != v && edges.find({std::min(u, v), std::max(u, v)}) == edges.end() && edges.find({std::max(u, v), std::min(u, v)}) == edges.end()) {
            edges.insert({std::min(u, v), std::max(u, v)});
        }
    }

    for (const auto& edge : edges) {
        file << edge.first << " " << edge.second << "\n";
    }

    // Fechar arquivo
    file.close();

    std::cout << "Arquivo 'grafo.txt' gerado com sucesso!\n";

    return 0;
}
