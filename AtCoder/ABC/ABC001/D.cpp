#include<iostream>
#include<cstdio>
using namespace std;

#define INTERVAL 12
#define HOUR 24

int main(){

    int n;
    cin >> n;
    int start,end;
    int m_start,m_end;
    int dis_start,dis_end;
    int ans_start,ans_end;
    int tm[1000] = {0};

    for(int i = 0;i < n;i++){
        scanf("%d-%d",&start,&end);
        m_start = (start / 100) * 60 + (start % 100);
        dis_start = m_start % 5;
        m_end = (end / 100) * 60 + (end % 100);
        dis_end = m_end % 5;
        //cout << dis_end << endl;

        //cout << start << " " << end << endl;
        //cout << m_start << " " << m_end << endl;

        if(dis_start != 0){
            m_start = m_start - dis_start;
        }            
                    
        if((end % 100)+ dis_end >=60){
            m_end = (end / 100 + 1)*60;
            //cout << "a" << endl;
        }else if(dis_end != 0){
            m_end = m_end + (5-dis_end); 
        }

        //cout << m_end << endl;
        tm[m_start / 5]++;
        tm[m_end / 5]--;
    }


    
    for(int i = 1;i < INTERVAL*HOUR;i++){
        tm[i] = tm[i]+tm[i-1];
    }
    
    int j = 0;
    while(j < INTERVAL*HOUR){
        if(tm[j] > 0){
            ans_start = (j / 12)*100 + (j % 12)*5;
            int k = j;
            while(tm[k] > 0){
                k++;
            }
            ans_end = (k / 12)*100 + (k % 12)*5;
            printf("%04d-%04d\n",ans_start,ans_end);
            j = k+1;
        }else{
            j++;
        }

    }


    //cout << start << " " << end << endl;


    return 0;
}
