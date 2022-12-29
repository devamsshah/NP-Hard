/**********
 * Name: Devam Shah
 * Project: Sum Subset Problem
 * NP-HARD PROBLEM SERIES
 **********/
/**
* This is an NP-Hard problem called "subset sum"
 * for this problem, you are supposed to find if there exists any subsets of the given set whose elements add up to the desired integer
 * this problem is NP-Hard and so it is thought to be efficiently solvable (usually on large data sets) by quantum computers
 * However, to understand how one can solve NP-Hard problems such as these, i have made a program that Not only tells you if there are any subsets whose elements sum to the desired integer
 * but also display the subset
 * This program's time complexity is O(2^n)
 * This is because the number of combination it has to iterate through is 2^n, wher n is the number of integers in the given set
 * this means that for each given set, the number of all possible subsets is 2^n
 * a set of all possible subsets of any given set is called a power set
 * Since this algorithm uses recursion, it consumes much more time
 * If it used a nested "for loop" then the time complexity would be much smaller resulting in a more efficient algorithm
 * I am currently working on a program that uses a nested "for loop" to make the algorithm more efficient
 * The new algorithm will use an array of linked lists instead of vector<vector<int> to reduce storage consumption and time complexity
*/
#include <iostream>
#include <vector>
using namespace std;

void allPossibleSubsets(vector<int>& orignialSet, vector<vector<int>>& setOfSubset, vector<int>& subset, int index){
    setOfSubset.push_back(subset);
    for (int i = index; i < orignialSet.size(); i++) {
        subset.push_back(orignialSet[i]);
        allPossibleSubsets(orignialSet, setOfSubset, subset, i + 1);
        subset.pop_back();
    }
    return;
}
vector<vector<int> > subsets(vector<int>& orignialSet){
    vector<int> subset;
    vector<vector<int>> setOfSubset;
    int index = 0;
    allPossibleSubsets(orignialSet, setOfSubset, subset, index);
    return setOfSubset;
}
bool sumChecker(vector<int> subset, int sum){
    int summation = 0;
    for (int i = 0; i < subset.size(); ++i) {summation = summation + subset[i];}
    if(summation==sum)
        return true;
    return false;
}
vector<int> vectorOfSums(vector<vector<int>> res, int sum){
    int count = 0;
    vector<int> sumVec;
    for (int i = 0; i < res.size(); ++i) {
        if(sumChecker(res.at(i), sum)){
            sumVec.push_back(1);
            sumVec[count] = i;
            count++;
        }else{
            continue;
        }
    }
    return sumVec;
}
int main(){
    int sum, sizeOfVector;
    vector<int> set;
    cout<<"enter size of set: "<<endl;
    cin>>sizeOfVector;
    while(sizeOfVector>27){
        cout << "Please enter a number that is less than 28." << endl;
        cout << "Try again" <<endl;
        cout<<"enter size of set: "<<endl;
        cin>>sizeOfVector;
    }
    cout<<"enter the elements of the set: "<< endl;
    for (int i = 0; i < sizeOfVector; ++i) {
        set.push_back(1);
        cin>>set[i];
    }
    cout<< "enter the sum you want to check for" << endl;
    cin>>sum;
    vector<vector<int>> res = subsets(set);
    vector<int> sumVec = vectorOfSums(res, sum);
    if(sumVec.size()==0){
        cout<< "Sorry, there are no possible subsets that sum to the given integer" << endl;
    }
    else{
        cout << "Following are the subsets that sum to " << sum << ": " << endl;
        for (int i = 0; i < sumVec.size(); i++) {
            cout << "Subset " << i + 1 << ": \t{" << res[sumVec[i]][0];
            for (int j = 1; j < res[sumVec[i]].size(); j++)
                cout << ", " << res[sumVec[i]][j];
            cout << "}" << endl;
        }
    }
    return 0;
}
