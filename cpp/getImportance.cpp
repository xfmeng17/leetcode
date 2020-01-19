/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
  int getImportance(vector<Employee *> employees, int id) {
    // return func1(employees, id);
    return func2(employees, id);
  }

  // unorder_map
  int func1(vector<Employee *> employees, int id) {
    int ans = 0;
    unordered_map<int, Employee *> umap;
    for (int i = 0; i < employees.size(); i++) {
      umap.insert(make_pair(employees[i]->id, employees[i]));
    }
    queue<int> queue;
    queue.push(id);
    while (!queue.empty()) {
      Employee *e = umap.at(queue.front());
      ans += e->importance;
      for (int i = 0; i < e->subordinates.size(); i++) {
        queue.push(e->subordinates[i]);
      }
      queue.pop();
    }
    return ans;
  }

  // unorder_map with using ::operator[]
  // DFS not queue
  int func2(vector<Employee *> employees, int id) {
    int ans = 0;
    unordered_map<int, Employee *> umap;
    for (const auto e : employees) {
      umap[e->id] = e;
    }
    return dfs(umap, id);
  }
  int dfs(unordered_map<int, Employee *> &umap, const int id) {
    int sum = umap[id]->importance;
    for (const auto sub : umap[id]->subordinates) {
      sum += dfs(umap, sub);
    }
    return sum;
  }
};
