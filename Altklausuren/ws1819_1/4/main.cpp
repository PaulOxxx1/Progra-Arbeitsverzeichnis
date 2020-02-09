#include<vector>
#include<iostream>
#include<fstream>

template<typename T>
struct vertex {
    T data;
    std::vector<vertex*> neighbors;

    int add_neighbor(vertex* v) {
        assert(v);                  // assert that the pointer is valid (not null)
        neighbors.push_back(v);     // add neighbor
        return neighbors.size();    // return new number of neighbors
    }
};


template<typename T>
struct graph {
    std::vector<vertex<T>>* vertices;

    graph(char* filename) {
        assert(filename);   // assert that the pointer is valid (not null)
        vertices = new std::vector<vertex<int>>;    // since "vertices" is a pointer, the vector is allocated on the heap

        std::ifstream ifs(filename);    // open input file
        int n; ifs >> n;
        assert(n>=0);   // no negative number of vertices

        // create all vertices
        for (int i=0;i<n;i++) {
            vertex<T> new_vertex;
            vertices->push_back(new_vertex);
        }

        // create all edges
        for (int i=0;i<n;i++) {
            int num_edges; ifs >> num_edges;
            assert(num_edges>=0);   // no negative number of edges
            for (int j=0;j<num_edges;j++) {
                int target_index; ifs >> target_index;
                assert(target_index>=0 && target_index<vertices->size());   // assert that index is in valid range
                vertices->at(i).add_neighbor(&vertices->at(target_index));  // add_neighbor accepts pointers, therefore we must use "&"
            }
        }
    }

    ~graph() {
        delete vertices;    // delete the vector on the heap
    }

    void to_dot() const {
        std::ofstream ofs("graph.dot");
        ofs << "digraph {" << std::endl;
        long i=0;
        for (auto v_it=vertices->begin();
                  v_it!=vertices->end();v_it++)
            ofs << (long)(&*v_it) << "[label=\"" << i++ << " ("
                << v_it->data << ")" << "\"]" << std::endl;
        for (auto v_it=vertices->begin();
                  v_it!=vertices->end();v_it++)
            for (auto n_it=v_it->neighbors.begin();
                      n_it!=v_it->neighbors.end();n_it++)
                ofs << (long)(&*v_it) << "->"
                    << (long)(*n_it) << std::endl;
        ofs << "}" << std::endl;
        ofs.close();
    }

    bool is_path(const std::vector<int>& path) {
        // if remaining path is empty ("path" only contains one number), we have arrived at our destination, and it is a valid path
        if (path.size() <= 1) return true;

        // if remaining path is not empty, check if next step is valid

        // create two helpful pointers to avoid a lot of clutter in the code
        vertex<T>* start_vertex = &vertices->at(path[0]);
        vertex<T>* next_vertex  = &vertices->at(path[1]);

        // look in neighbor list of start vertex for next vertex along path
        bool found = false;
        for (int i=0;i<start_vertex->neighbors.size();i++) {
            if (start_vertex->neighbors[i] == next_vertex) {
                found = true;
                break;
            }
        }

        if (found) {
            // since the next vertex is valid, we can recursively check the remaining path
            // by applying "is_path" again with a shorter path
            std::vector<int> remaining_path;    // since "path" is const, we have to make a copy
            for (int i=0;i<path.size()-1;i++) {
                remaining_path.push_back(path[i+1]);
            }
            return is_path(remaining_path);
        }

        // the next vertex was not found, therefore it is not a valid path
        return false;
    }
};


int main(int c, char* v[]) {
    if (c!=2) throw 42;
    graph<int> g(v[1]);
    g.to_dot();
    std::vector<int> p={4,3,0,1,2,3};
    std::cout << g.is_path(p) << std::endl;
    return 0;
}