// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <algorithm>
#include <vector>  // vector

// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;
        typedef std::pair<vertex_descriptor, vertex_descriptor> edge_descriptor;

        typedef std::vector<vertex_descriptor>::const_iterator vertex_iterator;
        typedef std::vector<edge_descriptor>::iterator edge_iterator;
        typedef std::vector<vertex_descriptor>::const_iterator adjacency_iterator;

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param vertex_descriptor v1 by value
         * @param vertex_descriptor v2 by value
         * @param Graph g by reference
         * return new pair with an edge descriptor and bool
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor v1, vertex_descriptor v2, Graph& g) {
            edge_descriptor ed = std::make_pair(v1, v2);
            bool            b  = false;

	        std::vector<edge_descriptor>::iterator it = std::find(g._edge.begin(), g._edge.end(), ed);
	        b = (it == g._edge.end());
	        if(b){
	            g._edge.push_back(ed);
		        g._g[ed.first].push_back(ed.second);
		        std::sort(g._edge.begin(), g._edge.end());
		        std::sort(g._g[ed.first].begin(), g._g[ed.first].end());
	        }
            assert(g.valid());
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
         * @param Graph g by reference
         * return vertex descriptor oh the old vertex size.
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            vertex_descriptor v = g._vertex.size();
	        g._vertex.push_back(v);
	        g._g.push_back(std::vector<vertex_descriptor>());
            assert(g.valid());
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param vertex_descriptor v by value
         * @param Graph g by const reference
         * return a new pair of adjacency iterators that are the beginning and end of adjacent vertices
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor v, const Graph& g) {
            assert(g.valid());
            return std::make_pair(g._g[v].begin(), g._g[v].end());}

        // ----
        // edge
        // ----

        /**
         * @param vertex_descriptor v1 by value
         * @param vertex_descriptor v2 by value
         * @param Graph g const reference
         * return pair of edge descriptor and bool. Bool is false is edge doesn't exist
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor v1, vertex_descriptor v2, Graph& g) {
            edge_descriptor ed = std::make_pair(v1, v2);
	        bool b = std::find(g._edge.begin(), g._edge.end(), ed) != g._edge.end();
            assert(g.valid());
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * @param Graph g by const reference
         * return pair of edges to show the begining and end of all edges
         */
        friend std::pair<edge_iterator, edge_iterator> edges (Graph& g) {
            assert(g.valid());
            return std::make_pair(g._edge.begin(), g._edge.end());}

        // ---------
        // num_edges
        // ---------

        /**
         * @param Graph g by const reference
         * return size of _edge
         */
        friend edges_size_type num_edges (const Graph& g) {
            assert(g.valid());
            return g._edge.size();}

        // ------------
        // num_vertices
        // ------------

        /**
         * @param Graph g by const reference
         * return the size of _vertex
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            assert(g.valid());
            return g._vertex.size();}

        // ------
        // source
        // ------

        /**
         * @param edge_descriptor ed by value
         * @param Graph g by const reference
         * return vertex descriptor that is the desired edge
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
            assert(g.valid());
            return ed.first;}

        // ------
        // target
        // ------

        /**
         * @param edge_descriptor ed by value
         * @param Graph g by const reference
         * return vertex descriptor that sees if edge exists or not 
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {
            assert(g.valid());
            return ed.second;}

        // ------
        // vertex
        // ------

        /**
         * @param vertices_size_type v by value
         * @param Graph g by const reference
         * return vertex descriptor that is the desired vertex value
         */
        friend vertex_descriptor vertex (vertices_size_type v, const Graph& g) {
	        if(g._g.size() == 0){
		      return 0;
	        }
            assert(g.valid());
            return g._vertex[v];}

        // --------
        // vertices
        // --------

        /**
         * @param Graph g by const reference
         * return pair of vertex iterators that are the beginning and end of the set of vertex 
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {
            assert(g.valid());
            return std::make_pair(g._vertex.begin(), g._vertex.end());}

    private:
        // ----
        // data
        // ----

        std::vector< std::vector<vertex_descriptor> > _g;
	    std::vector<vertex_descriptor> _vertex;
	    std::vector<edge_descriptor> _edge;

        // -----
        // valid
        // -----

        /**
         * checks if graph and vertex size are the same
         */
        bool valid () const {
            if(_g.size() != _vertex.size())
                return false;
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * @param vector of vectors of type vector_descriptor g by value
         * @param vector of type vector_descriptor edge by value
         * @param vector of type vector_descriptor vertex by value
         * parameters are assigned to their respective data members 
         */
        Graph (std::vector<std::vector<vertex_descriptor>> g = std::vector<std::vector<vertex_descriptor>>(), std::vector<vertex_descriptor> vertex = std::vector<vertex_descriptor>(), std::vector<edge_descriptor> edge = std::vector<edge_descriptor>()) : _g(g), _vertex(vertex),_edge(edge){
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h
