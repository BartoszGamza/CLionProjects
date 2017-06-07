#include<iostream>
#include<string.h>
#include <sstream>
#include<map>

using namespace std;

struct Vertice{
    map < int, double > adjacency;
};

struct Graph{
    Vertice * vert;
    int verts;
};

void insertEdge(Graph &g, int u, int v, double weight){
    g.vert[u].adjacency[v] = weight;

}

void loadGraph(Graph &g, int n, int m){
    g.verts = n;
    g.vert = new Vertice[n];
    Vertice * temp;

    int u,v,w;
    for (int i = 0; i < m; i++){
        cin >> u;
        cin >> v;
        cin >> w;
        insertEdge(g,u,v,w);
    }
}

bool edgeExist(Graph &g, int u, int v){
    return g.vert[u].adjacency.count(v);
}

bool findEdge(Graph &g, int u, int v, double &weight){
    if (u == v) {
        weight = 0;
        return true;
    }
    if (edgeExist(g, u, v)){
        weight = g.vert[u].adjacency[v];
        return true;
    };
    return false;
}

void showAsMatrix(Graph &g){
    double weight;
    bool exist;
    for (int i = 0; i < g.verts; i++){

        for (int j = 0; j < g.verts; j++){
            exist = findEdge(g, i, j, weight);

            if (exist){
                cout << weight << ",";
            }
            else
                cout << '-' << ',';
        }
        cout << endl;
    }
}

void showAsArrayOfLists(Graph &g){
    for (int i = 0; i < g.verts; i++){
        cout << i << ':';
        for (    map<int, double>::iterator it = g.vert[i].adjacency.begin(); it != g.vert[i].adjacency.end(); it++){
            cout << it->first << '(' << it ->second << "),";
        }
        cout << endl;
    }
}


bool isCommand(const string command,const char *mnemonic){
    return command==mnemonic;
}


int main(){
    string line;
    string command;
    Graph *graph;
    int currentT=0;
    int value;
    cout << "START" << endl;
    while(true){
        getline(cin,line);
        std::stringstream stream(line);
        stream >> command;
        if(line=="" || command[0]=='#')
        {
            // ignore empty line and comment
            continue;
        }

        // copy line on output with exclamation mark
        cout << "!" << line << endl;;

        // change to uppercase
        command[0]=toupper(command[0]);
        command[1]=toupper(command[1]);

        // zero-argument command
        if(isCommand(command,"HA")){
            cout << "END OF EXECUTION" << endl;
            break;
        }
        // zero-argument command
        if(isCommand(command,"SM"))
        {
            showAsMatrix(graph[currentT]);
            continue;
        }

        if(isCommand(command,"SA"))
        {
            showAsArrayOfLists(graph[currentT]);
            continue;
        }


        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"LG"))
        {
            int m;
            stream >> m;
            loadGraph(graph[currentT],value,m);
            continue;
        }

        if(isCommand(command,"IE"))
        {
            int v;
            double w;
            stream >> v >> w;
            insertEdge(graph[currentT],value,v,w);
            continue;
        }

        if(isCommand(command,"FE"))
        {
            int v;
            stream >> v;
            double w;
            bool ret=findEdge(graph[currentT],value,v,w);

            if(ret)
                cout << w << endl;
            else
                cout << "false" << endl;
            continue;
        }


        if(isCommand(command,"CH"))
        {
            currentT=value;
            continue;
        }

        if(isCommand(command,"GO"))
        {
            graph=new Graph[value];
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
        return 1;
    }
}