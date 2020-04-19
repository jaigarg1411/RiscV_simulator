#ifndef CACHE_H
#define CACHE_H
#include <bits/stdc++.h>

using namespace std;
#define i_max 10000
int CacheSize,CacheBlockSize,NumberOfwaysSA;
int NumOfAcceses,NumofColdM,NumofConflictM,NumofCapacityM,Numofhits,TotalM;
int choice;
////FA////
bool MCT[i_max];
vector<int> FAtag;
vector< bool > FAvalid;
bool FAleastRecent[i_max];
int FAline;
////FA/////
////SA/////
vector<int> SAtag[i_max];
vector < bool > SAvalid[i_max];
bool SAleastRecent[i_max][i_max];
int saline;
/////SA////
////DM/////
vector<int> DMtag;
vector< bool > DMvalid;
int DMway;
//////
void startCache()
{
    cout<<"This is for $D configuration "<<endl;
    cout<<"For FA type press: 1\nFor SA type press: 2\nFor DM type press: 3"<<endl;
    cin>>choice;
    cout<<"Enter cache size "<<endl;
    cin>>CacheSize;
    cout<<"Enter Cache Block size"<<endl;
    cin>>CacheBlockSize;
    if(choice==2)
    {
        cout<<"Enter nuber of ways"<<endl;
        cin>>NumberOfwaysSA;
        saline = CacheSize/(NumberOfwaysSA*CacheBlockSize);
        ///initializing part
        for(int i=0;i<NumberOfwaysSA+3;i++)
        {
            for(int j=0 ;j<saline+3 ; j++)
            {
                SAtag[i].push_back(-1) ;
                SAvalid[i].push_back(false);
                SAleastRecent[i][j] = true;
            }
        }
    }
    else if(choice == 1)
    {
        FAline = CacheSize/CacheBlockSize;
        ////initializing part////
        for(int i=0;i<FAline+3;i++)
        {
            FAvalid.push_back(false);
            FAleastRecent[i] = true;
        }
        for(int i=0;i<FAline+3;i++)
            FAtag.push_back(-1);
        
    }
    else if(choice == 3)
    {
        DMway = CacheSize/CacheBlockSize;
        for(int i=0;i<DMway+3;i++)
        {
            DMvalid.push_back(false);
            DMtag.push_back(-1);
        }
        
            
    }


    
}
bool cacheRead(int RZ )
{
    
    NumOfAcceses++;
    
    bool isFull = true;
    if(choice == 1)
    {
        for(int i=0;i<FAline;i++)
        {
            if(RZ>=FAtag[i]&&RZ<(FAtag[i]+CacheBlockSize)&&FAvalid[i])
            {
                FAleastRecent[i] = false;
                Numofhits++;
                return true;
            }
            else if(FAvalid[i]==false)
                isFull = false;
        }
        if(isFull == false)
        {
            NumofColdM++;
            return false ;
        }
        else
        {
            NumofCapacityM++;
            return false;
        }
    }
    else if(choice == 2)
    {
        int set = RZ%NumberOfwaysSA;
        bool isConflict = false ;
        for(int i=0;i<saline;i++)
        {
            if(RZ>=SAtag[set][i]&&RZ<(SAtag[set][i]+CacheBlockSize)&&SAvalid[set][i])
            {
                SAleastRecent[set][i] = false; 
                Numofhits++;
                return true;
            }
            else if((RZ<SAtag[set][i]||RZ>=(SAtag[set][i]+CacheBlockSize))&&SAvalid[set][i]&&MCT[RZ])
            {
                isConflict = true;
            }
            else if(SAvalid[set][i]==false)
                isFull = false;
        }
        if(isFull == false)
        {
            NumofColdM++;
            return false;
        }
        else if(isConflict)
        {
            NumofConflictM++;
            return false;
        }
        else 
        {
            NumofCapacityM++;
            return false;
        }

    }
    else if(choice ==3)
    {
        int set = RZ%DMway;
        bool isConflict = false ;
        if(RZ>=DMtag[set]&&RZ<(DMtag[set]+CacheBlockSize)&&DMvalid[set]==true)
        {
                Numofhits++;
                return true;
        }
        else if(!DMvalid[set])
        {
            NumofColdM++;
            return false;
        }
        else if((RZ<DMtag[set]||RZ>=(DMtag[set]+CacheBlockSize))&&DMvalid[set]==true&&MCT[RZ])
        {
            NumofConflictM++;
            return false;
        }
        else
        {
            NumofCapacityM++;
            return false;
        }     
    }

    
}

void cacheWrite(int rowi,int coli)
{
    
    int replaceTag =-1,i;
    if(choice == 1)
    {
        for(i=0;i<FAline;i++)
            if(!FAvalid[i])
                break;
        if(i<FAline)
        {
            FAtag[i] = 4*rowi + coli/2;
            FAvalid[i] = true;
            FAleastRecent[i] = true;
        }
        else
        {

            for(int i=0;i<FAline;i++)
            {
                if(FAleastRecent[i] == true)
                {
                    replaceTag = i;
                    break;
                }
            }
            if(replaceTag == -1)
                replaceTag = 0;
            
            FAtag[replaceTag] = rowi*4+coli/2;
            FAvalid[replaceTag] = true;
            FAleastRecent[replaceTag] = true; 
        }
    }
    else if(choice == 2)
    {
        int set = (4*rowi+coli/2)%NumberOfwaysSA;
        for(i=0;i<saline;i++)
            if(!SAvalid[set][i])
                break;
        if(i<saline)
        {
            SAtag[set][i] = 4*rowi + coli/2;
            SAvalid[set][i] = true;
            SAleastRecent[set][replaceTag] = true;
        }
        else
        {
            for(int i=0;i<saline;i++)
            {
                if(SAleastRecent[set][i] == true)
                {
                    replaceTag = i;
                    break;
                }
            }
            if(replaceTag == -1)
                replaceTag = 0;
            SAtag[set][replaceTag] = (4*rowi+coli/2);
            SAvalid[set][replaceTag] = true;
            SAleastRecent[set][replaceTag] = true;
            MCT[4*rowi+coli/2] = true;
        }

    }
    else if(choice == 3)
    {
        int set = (4*rowi+coli/2)%DMway;
        
        DMtag[set] = (4*rowi+coli/2);
        DMvalid[set] = true;
        MCT[4*rowi+coli/2] = true;
     
    }
        
}
void printCache()
{
    cout<<"Number of cache access "<<NumOfAcceses<<endl;
    cout<<"Number of cache hit "<<Numofhits<<endl;
    cout<<"Number of cache miss "<<NumOfAcceses-Numofhits<<endl;
    cout<<"Number of conflict miss "<<NumofConflictM<<endl;
    cout<<"Number of capacity miss "<<NumofCapacityM<<endl;
    cout<<"Number of cold miss  "<<NumofColdM<<endl;   
}
#endif