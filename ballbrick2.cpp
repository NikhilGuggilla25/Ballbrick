#include<bits/stdc++.h>
#include<string>
using namespace std;
int i,j,value;
char W='W',G='G',O='O';
int w=(int)W;
int g=(int)G;
int o=(int)O;
vector<vector<int>> matrix(i, vector<int> (j,value));
int n=matrix.size();
int ballcount;
string direction;
void output()
{
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==w) {cout<<"w"<<"  ";}
            else if(matrix[i][j]==g) {cout<<"G"<<"  ";}
            else if(matrix[i][j]==o) {cout<<"O"<<"  ";}
            else if(matrix[i][j]==0) {cout<<" "<<"  ";}
            else 
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }  
    cout<<"ball count "<<ballcount;
    cout<<endl;
}
void result()
{   
    int count=(n-2)*(n-2);
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if(matrix[i][j]>0 && ballcount==0) { cout<<"you lost the game"; break;}
            else if(matrix[i][j]==0 && ballcount>=0) {count--;}
        }
    }
    if(count==0) {cout<<"You win HURRAY..!!";}
}
void LD()
{
    int tempj=(n/2)-1;
    for(i=n-2;i>0;i--)
    {
        if((matrix[i][tempj])!=w && (matrix[i][tempj])>0)
        {
            (matrix[i][tempj])--; 
            ballcount--; 
            swap(matrix[n-1][n/2],matrix[n-1][(n/2)-1]);
            break;
        }
        if((matrix[i][tempj])==w) 
        {
            for(tempj=1;tempj<n;tempj++)
            {
                if((matrix[i][tempj])>0 && (matrix[i][tempj])!=w) {(matrix[i][tempj])--; ballcount--; break;}
                if((matrix[i][tempj])==w) {ballcount--; break;}
            }
        }
    }
    output();
    result();
    swap(matrix[n-1][n/2],matrix[n-1][(n/2)-1]);
}
void RD()
{
    int tempj=(n/2)+1;
    for(i=n-2;i>0;i--)
    {
        if((matrix[i][tempj])!=w && (matrix[i][tempj])>0) 
        {
            (matrix[i][tempj])--; 
            ballcount--; 
            swap(matrix[n-1][n/2],matrix[n-1][(n/2)+1]);
            break;
        }
            if((matrix[i][tempj])==w) 
        {
            for(tempj=n-2;tempj>=0;tempj--)
            {
                if((matrix[i][tempj])>0) {(matrix[i][tempj])--; ballcount--; break;}
                if((matrix[i][tempj])==w) {ballcount--; break;}
            }
        }
    }
    output();
    result();
    swap(matrix[n-1][n/2],matrix[n-1][(n/2)+1]);
}
void ST()
{
    int tempj=(n/2);
    for(i=n-2;i>0;i--)
    {
        if((matrix[i][tempj])>0) 
        { (matrix[i][tempj])=(matrix[i][tempj])-1; break; }
    }
    output();
    result();
}

int main()
{
    cout<<"enter size of the matrix : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        vector<int> temp;
        for(j=0;j<n;j++)
        {
            if(i==0 || j==0 || j==n-1 ) {temp.push_back(w);}
            else if((i==n-1) && (j!=0 || j!=n-1) && (j!=(n/2))) {temp.push_back(g);}
            else if(i==n-1 && j==(n/2)) {temp.push_back(o);}
            else
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }
    string ans="Y";
    int tempi,tempj;
    int tempvalue;
    while(ans=="Y")
    {
        cout<<"enter the brick's position and brick type : ";
        cin>>tempi>>tempj>>tempvalue;
        matrix[tempi][tempj]=tempvalue;
        cout<<"Do you want to continue ";
        cin>>ans;
    }
    cout<<"enter ball count ";
    cin>>ballcount;
    int count;
    output();
    while(ballcount>0)
    { 
        cout<<"enter the direction in which ball need to traverse : ";
        cin>>direction;
        if(direction=="LD") {LD();}
        if(direction=="RD") {RD();}
        if(direction=="ST") {ST();}
    }
return 0;
}
