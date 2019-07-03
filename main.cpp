#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <random>

using namespace std;

const int vertices = 50;
const double edgeDensity = 0.19;

class Graph {
private:
    int vertices;
    double edgeDensity;
    int **graph;
public:
    Graph(int vertices = 0, double edgeDensity = 0.0, int **graph = nullptr)
    {
        this->vertices = vertices;
        this->edgeDensity = edgeDensity;

        random_device rd; // access hardware RNG
        default_random_engine e(rd()); // seed the software PRNG
        uniform_int_distribution<int> cost(1, 10); // edge
        uniform_real_distribution<double> prob(0.0, 1.0); // range

        graph = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            graph[i] = new int[vertices];
        }
        cout<<this->vertices<<endl;
        for (int i = 0; i < this->vertices; i++) {
            for (int j = 0; j < this->vertices; j++) {
                if (i == j) graph[i][j] = 0;
                else if (prob(e) < this->edgeDensity) {
                    graph[i][j] = cost(e);
                    graph[j][i] = cost(e);
                }
                else
                    graph[i][j] = graph[j][i] = 0;
            }
        }
        display_graph();
    }
    void display_graph()
    {
        for (int i = 0; i < this->vertices; i++) {
            for (int j = 0; j < this->vertices; j++) {
                cout<<this->graph[i][j]<<' ';
            }
            cout<<endl;
        }
    }
};

int main(void)
{
    Graph G{vertices, edgeDensity};

    return 0;
}

