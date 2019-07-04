import networkx as N
import matplotlib.pyplot as plt

MyGraph = N.Graph()
color_map = [] # green for the most degree centrality node , blue otherwise
iter=0 #iteretor

file = open("demo.txt", "r")
nodes_edges = file.readline() #the first line containing nodes and edges
for x in nodes_edges:
    List_nodes_edges = nodes_edges.split(" ") #list of nodes and edges

while(iter<int(nodes_edges[0])):
    MyGraph.add_node(iter) #Adding nodes to my graph
    iter+=1

for x in file: #Looping on my file line by line
    edges = x.split(" ")  #Spliting my line to (node , node , weight)
    MyGraph.add_weighted_edges_from([(int(edges[0]),int(edges[1]),int(edges[2]))]) #Adding my edges to my graph

degree = N.degree_centrality(MyGraph) #List degree centrality of all nodes in [degree]
max_degree = degree[0]

for x in degree: #serching in my degree list about the max degree
    if max_degree<degree[x]:
        max_degree=degree[x]

for x in degree: #Pushing green or blue in the color map list depending on the max degree
    if max_degree == degree[x]:
        color_map.append('green')
    else:
        color_map.append('blue')

labels=N.draw_networkx_labels(MyGraph,pos=N.circular_layout(MyGraph)) #Writing labels on my nodes
edge_labels=N.draw_networkx_edge_labels(MyGraph,pos=N.circular_layout(MyGraph)) #Writing labels on my edges
N.draw_circular(MyGraph,node_color = color_map) #Drawing my graph in circular form with colors in color_map list
plt.show()
