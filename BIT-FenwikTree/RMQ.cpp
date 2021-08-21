source   :   https://cp-algorithms.com/data_structures/fenwick.html

class MinBIT{
     /* updation  : val at I is replaced by new_val [ new_val <= val ]
      * minVal    : min val from 1 to index I
      
                  : 1 based Indexing 
      */
      
      vector<int> B;
      int n;
      MinBIT( int n )
      {
          B=vector<in>(n+1);
          this->n = n;
          for(int i=0;i<=n;i++)
              B[i]=INT_MAX;
      }
      void update(int I,int val)
      {
            while( I <= n )
            { 
                B[I]=min(B[I],val);
                I+=I&-I;
            }
      }
      int minVal(int I)
      {
           int val=INT_MAX;
           while( I )
           {
                val=min(val,B[I]);
                I-=I&-I;
           }
           return val;
      }
};
    
      
