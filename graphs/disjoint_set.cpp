This data structure provides the following capabilities. We are given several elements, each of which is a separate set. A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is. The classical version also introduces a third operation, it can create a set from a new element.

Thus the basic interface of this data structure consists of only three operations:

make_set(v) - creates a new set consisting of the new element v
union_sets(a, b) - merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)
find_set(v) - returns the representative (also called leader) of the set that contains the element v. This representative is an element of its corresponding set. It is selected in each set by the data structure itself (and can change over time, namely after union_sets calls). This representative can be used to check if two elements are part of the same set or not. a and b are exactly in the same set, if find_set(a) == find_set(b). Otherwise they are in different sets.
As described in more detail later, the data structure allows you to do each of these operations in almost O(1) time on average.

Also in one of the subsections an alternative structure of a DSU is explained, which achieves a slower average complexity of O(logn), but can be more powerful than the regular DSU structure.




int parent[100000];
int rank[100000];

void makeSet(){
   for(int i=1;i<=n;i++){
   	parent[i]=i;
   	rank[i]=0;
   }
}
int findPar(int node){
   if(node == parent[node]){
   	return node;
   }
   return parent[node]=findPar(parent[node]);
}
void union(int u,int v){
   u=findPar(u);
   v=findPar(v);
   
   if(rank[u] < rank[v]){
       parent[u] = v;
   }
   else if(rank[v] < rank[u]){
   	parent[v] = u;
   }
   else{
   	parent[v] = u;
   	rank[u]++;
   }
}

void main(){
    makeSet();
    int m;
    cin>>m;
    while(m--){
       int u,v;
       union(u,v);
    }
    //if 
    if(findPar(2) !=findPar(3)){
    	cout<<"different component";
    }
    else{
    cout<<"same";
    }
}

TC:findPar will take 4(alpha)

    
       
     
