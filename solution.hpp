#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class SolutionThirtySeven{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
		//el problema puede verse como un problema de deteccion de ciclos en un grafo dirigido
		//si hay un ciclo significa que es imposible tomar todos los cursos, ya que algun curso depende
		//de si mismo directa o indirectamente
		
		vector<vector<int>> graph(numCourses);
		vector<int> inDegree(numCourses,0);
		//construir el grafo dirigido
		for(const auto& it: prerequisites){
			//esto es obligatorio segun el problema
			graph[it[1]].push_back(it[0]);
			inDegree[it[0]]++;
		}
		queue<int> q;
		//agregar todos los nodos con grado de entrada 0 a la cola
		for(int i=0; i<numCourses; ++i){
			if(inDegree[i]==0) q.push(i);
		}
		int c=0; //contador de cursos que se pueden tomar
		while(!q.empty()){
			int node=q.front();
			q.pop();
			c++;
			for(int neighbor: graph[node]){
				inDegree[neighbor]--;
				if(inDegree[neighbor]==0) q.push(neighbor);
			}
		}
		return c==numCourses;
	}
};

#endif