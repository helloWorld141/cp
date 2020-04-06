//
//  main.cpp
//  ParentingPartnering
//
//  Created by Kyle Nguyen on 4/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define pii pair<int, int>

using namespace std;

void printVector(vector<pii>& a) {
    for (pii i: a) printf("%d ", i.first);
    printf("\n");
}

string solve(vector<pii>& tasks) {
    string res = "";
    auto compare = [](pii a, pii b) {
        return (abs(a.first) < abs(b.first)) || (abs(a.first) == abs(b.first) && a.first < b.first);
    };
    sort(tasks.begin(), tasks.end(), compare);
    
    //printVector(tasks);
    
    queue<char> workers;
    workers.push('C');
    workers.push('J');

    unordered_map<int, char> assignment;
    
    for (pii time: tasks) {
        int t = time.first;
        int job_id = time.second;
        if (t >= 0) { // start new job
            if (workers.empty()) return "IMPOSSIBLE";
            // assign task
            assignment[job_id] = workers.front();
            workers.pop();
        } else { // release worker
            workers.push(assignment[job_id]);
        }
    }
    for (int i=0; i<tasks.size(); i++) {
        res+= assignment[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int test=0; test<T; test++) {
        int n;
        cin >> n;
        vector<pii> tasks; // pair include (time, task_id)
        for (int i=0; i<n; i++) {
            int s,e;
            cin >> s >> e;
            tasks.push_back(make_pair(s, i));
            tasks.push_back(make_pair(-e, i));
        }
        
        //printVector(tasks);
        
        string res = solve(tasks);
        printf("Case #%d: %s\n", test+1, res.c_str());
    }
    cin.get();
    return 0;
}

// test cases
/*
4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440
 */
