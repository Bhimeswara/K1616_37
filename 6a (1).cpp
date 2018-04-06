#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct process{
	int id, btime, atime, ctime, tat, wt, status;				
}p[10];


bool comp(process a, process b)
{
	return a.btime < b.btime;
}

void display(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"process ID: "<<p[i].id<<endl<<"process Burst time: "<<p[i].btime<<endl;
		cout<<"process arrival time: "<<p[i].atime<<endl<<"process status: "<<p[i].status;
		cout<<endl<<endl;
	}
}

void show(queue <int> gq)
{
	queue <int> g = gq;
	while(!g.empty())
	{
		cout<<"\t"<<g.front();
		g.pop();
	}
	cout<<"\n";
}

int main()
{
	int n,i,j,k;
	cout<<"Enter the number of process:\n";
	cin>>n;
	queue <int> o;
		
	cout<<"Enter the arrival time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the ariival time of P"<<i+1<<":"<<endl;
		cin>>p[i].atime;
		p[i].id = i+1;
	}

	cout<<"Enter the burst time of each process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the burst time of P"<<i+1<<":"<<endl;
		cin>>p[i].btime;
	}
	
	for(i=0;i<n;i++)
		p[i].status = 0;	
	
	sort(p, p+n, comp);
	

	int min = p[0].atime;
	int loc;
	for(i=0;i<n;i++)
	{
		if(min > p[i].atime)
			loc = i;
	}
	
	cout<<"processing P"<<p[loc].id<<" for "<<p[loc].btime<<" seconds"<<endl;
	int time = p[loc].btime;
	p[loc].status = 1;
	p[loc].ctime = time;
	o.push(p[loc].id);
	
	i=0;
	int process_count = 1;
	while(process_count!=n)
	{
		if(p[i].status!=1 && p[i].atime <= time)
		{
			cout<<"process P"<<p[i].id<<" for "<<p[i].btime<<" seconds"<<endl;
			time += p[i].btime;
			o.push(p[i].id);
			p[i].status = 1;
			p[i].ctime = time;
			process_count++;
		}
		i = (i+1)%n;
	}
	
	show(o);
	

	for(i=0;i<n;i++)
	{
		p[i].tat = p[i].ctime - p[i].atime;
	}
	
	for(i=0;i<n;i++)
	{
		p[i].wt = p[i].tat - p[i].btime;
	}
	
	
	int sum = 0;
	for(i=0;i<n;i++)
	{
		sum+= p[i].tat;
	}
	cout<<"\nAverage turnaround time is "<<sum/n<<endl;
	
	sum = 0;
	for(i=0;i<n;i++)
	{
		sum+= p[i].wt;
	}
	cout<<"\nAverage waiting time is "<<sum/n<<endl;

	return 0;
}

