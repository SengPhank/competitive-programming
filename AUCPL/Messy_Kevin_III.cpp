#include <bits/stdc++.h>
#include <queue>
#include <string>

int main(void) {
    long unsigned int numFixes; 
    std::string messyString, temp = "";
    std::deque<std::string> filePath;
    std::cin >> numFixes;
    
    for (long unsigned int i = 0; i < numFixes; i++) {
       std::cin >> messyString; 

       for (long unsigned int j = 0; j < messyString.size(); j++) {
            if (messyString[j] == '/') {
                if (temp.size() > 0) {
                    if (temp != ".") { 
                        filePath.push_front(temp);
                    }
                    temp = "";
                }
                continue;
            }

            if (j+1 < messyString.size() && messyString[j] == '.' && messyString[j+1] == '.') {
                j++;
                filePath.pop_front();
            } else {
                temp += messyString[j];
            }

        }

        // insert one last time
        if (temp.size() > 0) {
            filePath.push_front(temp);
            temp = "";
        }
        if (messyString[0] == '/') { // start with root if it originally started with root
            std::cout << "/";
        }
        while (filePath.size() > 1) {
            std::cout << filePath.back() << "/"; 
            filePath.pop_back();
        }
        if (filePath.size() == 1) {
            std::cout << filePath.back();
            filePath.pop_back();
        }
        std::cout << std::endl;

    }

    return 0;
}

/*t1
1
foo/bar/../baz

expected:
foo/baz
*/

/*t2
1
logs/./2025///july

expected:
logs/2025/july
*/

/*t3
1
///home/kevin/logs/../pathconverter.py

expected:
/home/kevin/pathconverter.py
*/

/*t4
3
dir1
/dir2
dir3/

expected:
dir1
/dir2
dir3
*/

/*t5
1
/foo/..

expected:
/
*/

/*t6
1
/a.birthday/b.day/../../

expected:
/
*/

/*t7
1 
////

expected:
/
*/