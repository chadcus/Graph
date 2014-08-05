/*
ogle Test Libraries:
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
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Graph.h TestGraph.c++ -o TestGraph -lgtest -lgtest_main -lpthread

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

/* Graph: add_vertex */
TYPED_TEST(TestGraph, add_vertex1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertex_descriptor ve = vertex(1, g);
    ASSERT_EQ(vdB, ve);
}

TYPED_TEST(TestGraph, add_vertex2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertex_descriptor ve = vertex(1, g);
    ASSERT_EQ(vdB, ve);

    vertex_descriptor vf = vertex(2, g);
    ASSERT_EQ(vdC, vf);
}

TYPED_TEST(TestGraph, add_vertex3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA;

    for(int i = 0; i < 25; ++i)
        vdA = add_vertex(g);

    vertex_descriptor vd = vertex(24, g);
    ASSERT_EQ(vdA, vd);
}
/*******************************/

/* Graph: vertex */
TYPED_TEST(TestGraph, vertex1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertex_descriptor ve = vertex(1, g);
    ASSERT_EQ(vdB, ve);
}

TYPED_TEST(TestGraph, vertex2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertex_descriptor ve = vertex(1, g);
    ASSERT_EQ(vdB, ve);

    vertex_descriptor vf = vertex(2, g);
    ASSERT_EQ(vdC, vf);
}

TYPED_TEST(TestGraph, vertex3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA;

    for(int i = 0; i < 25; ++i)
        vdA = add_vertex(g);

    vertex_descriptor vd = vertex(24, g);
    ASSERT_EQ(vdA, vd);
}
/*******************************/

/* Graph: num_vertices */
TYPED_TEST(TestGraph, num_vertices1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(0, vs);
}

TYPED_TEST(TestGraph, num_vertices2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertex_descriptor ve = vertex(1, g);
    ASSERT_EQ(vdB, ve);

    vertex_descriptor vf = vertex(2, g);
    ASSERT_EQ(vdC, vf);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(3, vs);
}

TYPED_TEST(TestGraph, num_vertices3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA;

    for(int i = 0; i < 25; ++i)
        vdA = add_vertex(g);

    vertex_descriptor vd = vertex(24, g);
    ASSERT_EQ(vdA, vd);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(25, vs);
}
/*******************************/

/* Graph: vertex_iterator(vertices) */
TYPED_TEST(TestGraph, vertex_iterator1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

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
    ASSERT_EQ(e, b);
}

TYPED_TEST(TestGraph, vertex_iterator2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA;

    for(int i = 0; i < 25; ++i)
        vdA = add_vertex(g);

    std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                             b = p.first;
    vertex_iterator                             e = p.second;

    while(b != e){
        ++b;
    }

    ASSERT_EQ(e, b);
}

TYPED_TEST(TestGraph, vertex_iterator3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA;

    for(int i = 0; i < 102; ++i)
        vdA = add_vertex(g);

    std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                             b = p.first;
    vertex_iterator                             e = p.second;

    vertex_iterator temp = b + 101;
    vertex_descriptor vd = *temp;

    ASSERT_EQ(vd, 101);
}
/*******************************/

/* Graph: add_edge */
TYPED_TEST(TestGraph, add_edge1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor ed = add_edge(vdA, vdB, g).first;
    edge_descriptor ed2 = add_edge(vdA, vdB, g).first;

    ASSERT_EQ(ed, ed2);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, add_edge2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    std::pair<edge_descriptor, bool> temp = add_edge(vdA, vdB, g);
    edge_descriptor ed = temp.first;

    /* Try to add the same edge, should not add it */
    std::pair<edge_descriptor, bool> temp2 = add_edge(vdA, vdB, g);
    bool result = temp2.second;

    ASSERT_FALSE(result);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, add_edge3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }
    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    ASSERT_EQ(num_edges(g), 100);
    ASSERT_EQ(num_vertices(g), 200);
}
/*******************************/

/* Graph: edge */
TYPED_TEST(TestGraph, edge1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor ed = add_edge(vdA, vdB, g).first;
    edge_descriptor ed2 = edge(vdA, vdB, g).first;

    ASSERT_EQ(ed, ed2);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, edge2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    add_edge(vdA, vdB, g);

    bool result = edge(vdB, vdA, g).second;

    ASSERT_FALSE(result);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, edge3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }
    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    bool test = edge(198, 199, g).second;

    ASSERT_TRUE(test);
    ASSERT_EQ(num_edges(g), 100);
    ASSERT_EQ(num_vertices(g), 200);
}
/*******************************/

/* Graph: num_edges */
TYPED_TEST(TestGraph, num_edges1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor ed = add_edge(vdA, vdB, g).first;

    ASSERT_EQ(num_edges(g), 1);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, num_edges2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    std::pair<edge_descriptor, bool> temp = add_edge(vdA, vdB, g);
    edge_descriptor ed = temp.first;

    /* Try to add the same edge, should not add it */
    std::pair<edge_descriptor, bool> temp2 = add_edge(vdA, vdB, g);
    bool result = temp2.second;

    ASSERT_FALSE(result);
    ASSERT_EQ(num_edges(g), 1);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, num_edges3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }
    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }
    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    ASSERT_EQ(num_edges(g), 150);
    ASSERT_EQ(num_vertices(g), 300);
}
/*******************************/

/* Graph: edge_iterator(edges) */
TYPED_TEST(TestGraph, edge_iterator1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;

    std::pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator                           b = p.first;
    edge_iterator                           e = p.second;

    ASSERT_EQ(*b, edAB);
    ++b;

    ASSERT_EQ(b, e);
}

TYPED_TEST(TestGraph, edge_iterator2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;

    std::pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator                           b = p.first;
    edge_iterator                           e = p.second;

    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edAB, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edAC, ed);}
    ++b;
    ASSERT_EQ(e, b);
}

TYPED_TEST(TestGraph, edge_iterator3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }
    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    std::pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator                           b = p.first;
    edge_iterator                           e = p.second;

    edge_iterator temp = b;
    for(int i = 0; i < 100; ++i)
        ++temp;
    ASSERT_EQ(temp, e);    

    ASSERT_EQ(num_edges(g), 100);
    ASSERT_EQ(num_vertices(g), 200);
}
/*******************************/

/* Graph: source */
TYPED_TEST(TestGraph, source1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor ed = add_edge(vdA, vdB, g).first;

    vertex_descriptor vA = source(ed, g);

    ASSERT_EQ(vA, 0);
    ASSERT_EQ(num_edges(g), 1);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, source2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    vertex_descriptor vA = source(ed, g);

    ASSERT_EQ(vA, 98);
    ASSERT_EQ(num_edges(g), 50);
    ASSERT_EQ(num_vertices(g), 100);
}

TYPED_TEST(TestGraph, source3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }
    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    vertex_descriptor vA = source(ed, g);

    ASSERT_EQ(vA, 198);
    ASSERT_EQ(num_edges(g), 100);
    ASSERT_EQ(num_vertices(g), 200);
}
/*******************************/

/* Graph: target */
TYPED_TEST(TestGraph, target1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor ed = add_edge(vdA, vdB, g).first;

    vertex_descriptor vA = target(ed, g);

    ASSERT_EQ(vA, 1);
    ASSERT_EQ(num_edges(g), 1);
    ASSERT_EQ(num_vertices(g), 2);
}

TYPED_TEST(TestGraph, target2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    vertex_descriptor vA = target(ed, g);

    ASSERT_EQ(vA, 99);
    ASSERT_EQ(num_edges(g), 50);
    ASSERT_EQ(num_vertices(g), 100);
}

TYPED_TEST(TestGraph, target3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA;
    vertex_descriptor vdB;
    edge_descriptor ed;

    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }
    for(int i = 0; i < 50; ++i)
    {
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ed = add_edge(vdA, vdB, g).first;
    }

    vertex_descriptor vA = target(ed, g);

    ASSERT_EQ(vA, 199);
    ASSERT_EQ(num_edges(g), 100);
    ASSERT_EQ(num_vertices(g), 200);
}
/*******************************/

/* Graph: adjacent_vertices */
TYPED_TEST(TestGraph, adjacent_vertices1) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

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
    ASSERT_EQ(e, b);
}

TYPED_TEST(TestGraph, adjacent_vertices2) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA = add_vertex(g);
    
    /* Internal Vector Resize Test */
    for(int i = 0; i < 11; ++i)
    {
        vertex_descriptor temp = add_vertex(g);
        edge_descriptor temp2 = add_edge(vdA, temp, g).first;
    }

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;

    adjacency_iterator test = b;
    for(int i = 0; i < 11; ++i)
        ++test;

    ASSERT_EQ(test, e);
}

TYPED_TEST(TestGraph, adjacent_vertices3) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA = add_vertex(g);
    
    /* Internal Vector Resize Test */
    for(int i = 0; i < 100; ++i)
    {
        vertex_descriptor temp = add_vertex(g);
        edge_descriptor temp2 = add_edge(vdA, temp, g).first;
    }

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;

    adjacency_iterator test = b;
    for(int i = 0; i < 100; ++i)
        ++test;
    
    ASSERT_EQ(test, e);
}

TYPED_TEST(TestGraph, adjacent_vertices4) 
{
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    vertex_descriptor vdA = add_vertex(g);
    
    /* Cyclic Test */
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);
    edge_descriptor edD = add_edge(vdA, vdD, g).first;
    edge_descriptor edB = add_edge(vdA, vdB, g).first;
    edge_descriptor edA = add_edge(vdA, vdA, g).first;
    edge_descriptor edC = add_edge(vdA, vdC, g).first;

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;

    /* First vertex in adjacency list is itself */
    ASSERT_EQ(*b, vdA);
    ++b;
    ASSERT_EQ(*b, vdB);
    ++b;
    ASSERT_EQ(*b, vdC);
    ++b;
    ASSERT_EQ(*b, vdD);
    ++b;
    ASSERT_EQ(b, e);
}
