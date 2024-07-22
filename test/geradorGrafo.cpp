#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <unordered_set>

using namespace std;

// Custom hash function for pair<int, int>
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main() {
    // Parâmetros dados
    int v, t, p, u;
    float s, dificuldade, conectividade;
    string arquivos[] = {"./test/aleatorio300-15-1.txt","./test/aleatorio300-150-1.txt","./test/aleatorio300-1500-1.txt",
                        "./test/aleatorio400-20-1.txt","./test/aleatorio400-200-1.txt","./test/aleatorio400-2000-1.txt",
                        "./test/aleatorio500-25-1.txt","./test/aleatorio500-250-1.txt","./test/aleatorio500-2500-1.txt",
                        "./test/aleatorio600-30-1.txt","./test/aleatorio600-300-1.txt","./test/aleatorio600-3000-1.txt",
                        "./test/aleatorio700-35-1.txt","./test/aleatorio700-350-1.txt","./test/aleatorio700-3500-1.txt",
                        "./test/aleatorio800-40-1.txt","./test/aleatorio800-400-1.txt","./test/aleatorio800-4000-1.txt",
                        "./test/aleatorio900-45-1.txt","./test/aleatorio900-450-1.txt","./test/aleatorio900-4500-1.txt",
                        "./test/aleatorio1000-50-1.txt","./test/aleatorio1000-500-1.txt","./test/aleatorio1000-5000-1.txt"};
    int k=2;
    for(int ii=0;ii<24;ii++){
        if(ii%3==0){
            k++;
        }
        v=k*100;
        s = v/2;
        if(ii%3!=0){
            s*=10;
        }
        dificuldade=1;
        if(ii%3==2){
            dificuldade=10;
        }
        conectividade=0.1;
        t= conectividade*v*(v+1)/2;
        p=t/10;
        // Abrir arquivo para escrita
        ofstream file(arquivos[ii]);
        if (!file.is_open()) {
            cerr << "Erro ao abrir o arquivo para escrita.\n";
            return 1;
        }

        // Configuração do gerador de números aleatórios
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> vertex_dis(-(s*dificuldade/20), (s*dificuldade/20));  // Coordenadas de vértices de 0 a 100
        file << v << " " << t << " " << p << "\n";
        // Gerar vértices
        for (int i = 0; i < v; ++i) {
            float x = vertex_dis(gen);
            float y = vertex_dis(gen);
            file << x << " " << y << "\n";
        }

        // Gerar trilhas
        uniform_int_distribution<int> vertex_dist(0, v - 1);  // Distribuição para vértices de 0 a v-1
        unordered_set<pair<int, int>, PairHash> edges;  // Usar PairHash como o hash

        while (edges.size() < t) {
            int u = vertex_dist(gen);
            int v = vertex_dist(gen);
            if (u != v) {
                edges.insert({min(u, v), max(u, v)});
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
            if (u != v && edges.find({min(u, v), max(u, v)}) == edges.end() && edges.find({max(u, v), min(u, v)}) == edges.end()) {
                edges.insert({min(u, v), max(u, v)});
            }
        }

        for (const auto& edge : edges) {
            file << edge.first << " " << edge.second << "\n";
        }
        file << s << " " << u << "\n";
        // Fechar arquivo
        file.close();

        cout << "Arquivo " << arquivos[ii]  << " gerado com sucesso!\n";
    }
    return 0;
}
