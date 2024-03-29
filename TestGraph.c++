// ----------------------------
// projects/graph/TestGraph.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

/*
Google Test Libraries:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

To compile the test:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Graph.c++ TestGraph.c++ -o TestGraph -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestGraph

To obtain coverage of the test:
    % gcov-4.7 -b Graph.c++ TestGraph.c++
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp"  // adjacency_list
#include "boost/graph/topological_sort.hpp"// topological_sort

#include "gtest/gtest.h"

#include "Graph.h"

#define ALL_TYPES	typedef typename TestFixture::graph_type         graph_type; \
    				typedef typename TestFixture::vertex_descriptor  vertex_descriptor; \
    				typedef typename TestFixture::edge_descriptor    edge_descriptor; \
    				typedef typename TestFixture::vertex_iterator    vertex_iterator; \
    				typedef typename TestFixture::edge_iterator      edge_iterator; \
    				typedef typename TestFixture::adjacency_iterator adjacency_iterator; \
    				typedef typename TestFixture::vertices_size_type vertices_size_type; \
    				typedef typename TestFixture::edges_size_type    edges_size_type; \

// ---------
// TestGraph
// ---------

template <typename G>
struct TestGraph : testing::Test {
    // --------
    // typedefs
    // --------

    typedef          G                     graph_type;
    typedef typename G::vertex_descriptor  vertex_descriptor;
    typedef typename G::edge_descriptor    edge_descriptor;
    typedef typename G::vertex_iterator    vertex_iterator;
    typedef typename G::edge_iterator      edge_iterator;
    typedef typename G::adjacency_iterator adjacency_iterator;
    typedef typename G::vertices_size_type vertices_size_type;
    typedef typename G::edges_size_type    edges_size_type;};

// directed, sparse, unweighted
// possibly connected
// possibly cyclic
typedef testing::Types<
            boost::adjacency_list<boost::setS, boost::vecS, boost::directedS>,
            Graph>
        my_types;

TYPED_TEST_CASE(TestGraph, my_types);

TYPED_TEST(TestGraph, Num_Vertices_1) {
    ALL_TYPES;

    graph_type g;

    add_vertex(g);

    ASSERT_EQ(num_vertices(g), 1);}

TYPED_TEST(TestGraph, Num_Vertices_2) {
    ALL_TYPES;

    graph_type g;

    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);

    ASSERT_EQ(num_vertices(g), 8);}

TYPED_TEST(TestGraph, Num_Vertices_3) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    ASSERT_EQ(vdA, 0);

    ASSERT_EQ(num_vertices(g), 1);}

TYPED_TEST(TestGraph, Add_Edge_1) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;

    std::pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_EQ(edAB,  p1.first);
    ASSERT_EQ(false, p1.second);}

TYPED_TEST(TestGraph, Add_Edge_2) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;
    std::pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    std::pair<edge_descriptor, bool> p2 = add_edge(vdA, vdC, g);
    std::pair<edge_descriptor, bool> p3 = add_edge(vdB, vdC, g);
    ASSERT_EQ(edAB,  p1.first);
    ASSERT_EQ(false, p1.second);
	ASSERT_EQ(edAC,  p2.first);
    ASSERT_EQ(false, p2.second);
    ASSERT_EQ(edBC,  p3.first);
    ASSERT_EQ(false, p3.second);}

TYPED_TEST(TestGraph, Add_Edge_3) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edCD = add_edge(vdC, vdD, g).first;

    std::pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    std::pair<edge_descriptor, bool> p2 = add_edge(vdC, vdD, g);
    ASSERT_EQ(edAB,  p1.first);
    ASSERT_EQ(false, p1.second);
	ASSERT_EQ(edCD,  p2.first);
    ASSERT_EQ(false, p2.second);}

TYPED_TEST(TestGraph, Add_Vertex_1) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    ASSERT_EQ(vdA, 0);}

TYPED_TEST(TestGraph, Add_Vertex_2) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    ASSERT_EQ(vdA, 0);

    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(vdB, 1);}

TYPED_TEST(TestGraph, Add_Vertex_3) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    ASSERT_EQ(vdA, 0);

    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(vdB, 1);

    vertex_descriptor vdC = add_vertex(g);
    ASSERT_EQ(vdC, 2);

    vertex_descriptor vdD = add_vertex(g);
    ASSERT_EQ(vdD, 3);}

 TYPED_TEST(TestGraph, Edge_1){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    ASSERT_TRUE(edge(vdA, vdB, g).second);
    ASSERT_EQ(edAB, edge(vdA, vdB, g).first);}

TYPED_TEST(TestGraph, Edge_2){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;
    ASSERT_TRUE(edge(vdA, vdB, g).second);
    ASSERT_EQ(edAB, edge(vdA, vdB, g).first);
	ASSERT_TRUE(edge(vdA, vdC, g).second);
    ASSERT_EQ(edAC, edge(vdA, vdC, g).first);}


TYPED_TEST(TestGraph, Edge_3){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;
    edge_descriptor edCD = add_edge(vdC, vdD, g).first;
    ASSERT_TRUE(edge(vdA, vdB, g).second);
    ASSERT_EQ(edAB, edge(vdA, vdB, g).first);
	ASSERT_TRUE(edge(vdB, vdC, g).second);
    ASSERT_EQ(edBC, edge(vdB, vdC, g).first);
    ASSERT_TRUE(edge(vdC, vdD, g).second);
    ASSERT_EQ(edCD, edge(vdC, vdD, g).first);}

TYPED_TEST(TestGraph, Edges_1) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;

    std::pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator b = p.first;
    edge_iterator e = p.second;

    if(b != e){
        edge_descriptor ed = *b;
        ASSERT_EQ(edAB, ed);
    }
    ++b;
    ASSERT_EQ(b, e);}

 TYPED_TEST(TestGraph, Edges_2) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;

    std::pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator b = p.first;
    edge_iterator e = p.second;

    if(b != e){
        edge_descriptor ed = *b;
        ASSERT_EQ(edAB, ed);
    }
    ++b;
    if(b != e){
        edge_descriptor ed = *b;
        ASSERT_EQ(edAC, ed);
    }
    ++b;
    ASSERT_EQ(b, e);}

 TYPED_TEST(TestGraph, Edges_3) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    std::pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator b = p.first;
    edge_iterator e = p.second;

    ASSERT_EQ(b, e);}

TYPED_TEST(TestGraph, Num_Edges_1) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;

	ASSERT_EQ(num_edges(g), 3);}

TYPED_TEST(TestGraph, Num_Edges_2) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

	ASSERT_EQ(num_edges(g), 0);}

TYPED_TEST(TestGraph, Num_Edges_3) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edBC = add_edge(vdB, vdC, g).first;

	ASSERT_EQ(num_edges(g), 2);}


TYPED_TEST(TestGraph, Vertices_1) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                             b = p.first;
    vertex_iterator                             e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdA, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    ASSERT_EQ(e, b);}

 TYPED_TEST(TestGraph, Vertices_2) {
    ALL_TYPES;

    graph_type g;

    std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                             b = p.first;
    vertex_iterator                             e = p.second;

    ASSERT_EQ(e, b);}

TYPED_TEST(TestGraph, Vertices_3) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);
    std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                             b = p.first;
    vertex_iterator                             e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdA, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdC, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdD, vd);}
    ++b;
    ASSERT_EQ(e, b);}

TYPED_TEST(TestGraph, Source_1){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    add_edge(vdA, vdB, g);
    ASSERT_EQ(source( edge(vdA, vdB, g).first, g), vdA);}

TYPED_TEST(TestGraph, Source_2){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    add_edge(vdB, vdA, g);
    ASSERT_EQ(source( edge(vdB, vdA, g).first, g), vdB);}

TYPED_TEST(TestGraph, Source_3){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edBA = add_edge(vdB, vdA, g).first;
    
    vertex_descriptor cvdA = source(edAB, g);
    vertex_descriptor cvdB = source(edBA, g);
    ASSERT_EQ(cvdA, vdA);
    ASSERT_EQ(cvdB, vdB);}

TYPED_TEST(TestGraph, Target_1){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    add_edge(vdA, vdB, g);
    ASSERT_EQ(target( edge(vdA, vdB, g).first, g), vdB);}

TYPED_TEST(TestGraph, Target_2){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    add_edge(vdB, vdA, g);
    ASSERT_EQ(target( edge(vdB, vdA, g).first, g), vdA);}

TYPED_TEST(TestGraph, Target_3){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edBA = add_edge(vdB, vdA, g).first;
    
    vertex_descriptor cvdA = target(edAB, g);
    vertex_descriptor cvdB = target(edBA, g);
    ASSERT_EQ(cvdA, vdB);
    ASSERT_EQ(cvdB, vdA);}

TYPED_TEST(TestGraph, Vertex_1){
    ALL_TYPES;
    graph_type g;

    ASSERT_EQ(vertex(0, g), 0);}

TYPED_TEST(TestGraph, Vertex_2){
    ALL_TYPES;
    graph_type g;
 	
 	vertex_descriptor vdA = add_vertex(g);
    
    ASSERT_EQ(vertex(0, g), vdA);}

TYPED_TEST(TestGraph, Vertex_3){
    ALL_TYPES;
    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);

    ASSERT_EQ(vertex(0, g), vdA);
    ASSERT_EQ(vertex(1, g), vdB);
    ASSERT_EQ(vertex(2, g), vdC);
    ASSERT_EQ(vertex(3, g), vdD);}

TYPED_TEST(TestGraph, Adjacent_Vertices_1) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    add_edge(vdA, vdB, g);
    add_edge(vdA, vdC, g);

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdC, vd);}
    ++b;
    ASSERT_EQ(e, b);}

 TYPED_TEST(TestGraph, Adjacent_Vertices_2) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;
    ASSERT_EQ(e, b);}

 TYPED_TEST(TestGraph, Adjacent_Vertices_3) {
    ALL_TYPES;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    add_edge(vdA, vdB, g);
    add_edge(vdA, vdC, g);

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdC, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;
    ASSERT_EQ(e, b);}