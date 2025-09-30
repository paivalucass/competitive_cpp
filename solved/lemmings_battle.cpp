#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;

    cin >> n;

    while (n--){
        priority_queue<int> sg;
        priority_queue<int> sb;
        int battlefield, greens, blues;
        cin >> battlefield >> greens >> blues;

        while (greens--){
            int v;
            cin >> v;
            sg.push(v);
        }

        while (blues--){
            int v;
            cin >> v;
            sb.push(v);
        }

        while (!sb.empty() && !sg.empty()){
            stack<int> stackb;
            stack<int> stackg; 
            int size;
            if (sb.size() > sg.size()){
                size = sg.size();
            }
            else{
                size = sb.size();
            }

            if (size > battlefield){
                size = battlefield;
            }

            for (int i = 0; i < size; ++i){
                int g = sg.top();
                sg.pop();
                int b = sb.top();
                sb.pop();
                if (g > b){
                    stackg.push(g-b);
                }
                else if (b > g){
                    stackb.push(b-g);
                }
                else{
                }
            }
            
            while (!stackb.empty() || !stackg.empty()){
                if (!stackb.empty()){
                    sb.push(stackb.top());
                    stackb.pop();
                }
                if (!stackg.empty()){
                    sg.push(stackg.top());
                    stackg.pop();
                }
            }
        }

        if (!sb.empty()){
            cout << "blue wins" << "\n";
            while (!sb.empty()){
                cout << sb.top() << "\n";
                sb.pop();
            }
        }
        else if (!sg.empty()){
            cout << "green wins" << "\n";
            while (!sg.empty()){
                cout << sg.top() << "\n";
                sg.pop();
            }
        }
        else{
            cout << "green and blue died" << "\n";
        }

        if (n != 0){
            cout << "\n";
        }
    }
}