#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, q;

struct role{
    unordered_set<string> op, source_type, source_name;
    bool is_valid(string op1, string type, string name){
        return (op.count(op1) || op.count("*")) && (source_type.count(type) || source_type.count("*")) && (source_name.count(name) || source_name.empty());
    }
};

// 一个角色的名称与其对应的操作和资源
unordered_map<string, role> sr; 
// ur为一个用户对应的角色组
// gr为一个用户组名称对应的角色组
unordered_map<string, vector<string> > ur, gr; 

void init(){
    while (n -- ){
        string name;
        cin >> name;

        int num;
        string s;

        cin >> num;
        while (num -- ){
            cin >> s;
            sr[name].op.insert(s);
        }

        cin >> num;
        while (num -- ){
            cin >> s;
            sr[name].source_type.insert(s);
        }

        cin >> num;
        while (num -- ){
            cin >> s;
            sr[name].source_name.insert(s);
        }
    }

    while (m -- ){
        string RoleName;
        int num;
        cin >> RoleName >> num;
        while (num -- ){
            string object, name;
            cin >> object >> name;
            if (object == "u") ur[name].push_back(RoleName);
            else gr[name].push_back(RoleName);
        }
    }

}

void query(){
    unordered_set<string> ug; // 该用户关联及该用户所属用户组关联的所有角色
    int num;
    string name;
    cin >> name >> num;
    ug.insert(ur[name].begin(), ur[name].end());

    while (num -- ){
        cin >> name;
        ug.insert(gr[name].begin(), gr[name].end());
    }

    string op_name, source_type, source_name;
    cin >> op_name >> source_type >> source_name;

    for (auto &t: ug)
        if (sr[t].is_valid(op_name, source_type, source_name)){
            puts("1");
            return ;
        }

    puts("0");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;

    init();

    while (q -- ) query();
}