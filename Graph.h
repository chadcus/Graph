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

        typedef int vertex_descriptor;  // fix!
        typedef std::pair<vertex_descriptor, vertex_descriptor> edge_descriptor;    // fix!

        typedef std::vector<vertex_descriptor>::const_iterator vertex_iterator;    // fix!
        typedef std::vector<edge_descriptor>::const_iterator edge_iterator;      // fix!
        typedef std::vector<vertex_descriptor>::const_iterator adjacency_iterator; // fix!

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * <your documentation>
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor v1, vertex_descriptor v2, Graph& g) {
            edge_descriptor ed = std::make_pair(v1, v2);
            bool            b  = false;

	    std::vector<edge_descriptor>::iterator it = std::find(g._edge.begin(), g._edge.end(), ed);
	    b = (it == g._edge.end());
	    if(b){
	        g._edge.push_back(ed);
		g._g[ed.first].push_back(ed.second);
	    }
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
         * <your documentation>
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            vertex_descriptor v = g._vertex.size();
	    g._vertex.push_back(v);
	    g._g.push_back(std::vector<vertex_descriptor>());
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * <your documentation>
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor v, const Graph& g) {
            adjacency_iterator b = g._g[v].begin();
            adjacency_iterator e = g._g[v].end();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * <your documentation>
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor v1, vertex_descriptor v2, const Graph& g) {
            edge_descriptor ed = std::make_pair(v1, v2);
            bool            b  = true;

	    b = std::find(g._edge.begin(), g._edge.end(), ed) != g._edge.end();
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * <your documentation>
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& g) {
            edge_iterator b = g._edge.begin();
            edge_iterator e = g._edge.end();
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * <your documentation>
         */
        friend edges_size_type num_edges (const Graph& g) {
            edges_size_type s = g._edge.size();
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph&) {
            vertices_size_type s = 1;
            return s;}

        // ------
        // source
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
            vertex_descriptor v = ed.first;
            return v;}

        // ------
        // target
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {
            vertex_descriptor v = ed.second;
            return v;}

        // ------
        // vertex
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor vertex (vertices_size_type v, const Graph& g) {
            vertex_descriptor vd = g._vertex[v];
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * <your documentation>
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {
            vertex_iterator b = g._vertex.begin();
            vertex_iterator e = g._vertex.end();
            return std::make_pair(b, e);}

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
         * <your documentation>
         */
        bool valid () const {
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Graph (std::vector<std::vector<vertex_descriptor>> g = std::vector<std::vector<vertex_descriptor>>(), std::vector<vertex_descriptor> vertex = std::vector<vertex_descriptor>(), std::vector<edge_descriptor> edge = std::vector<edge_descriptor>()) : _g(g), _vertex(vertex),_edge(edge){
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h
