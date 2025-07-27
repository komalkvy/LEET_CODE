class Solution {
public:
    void domain(vector<string>& d,string s){
        string num="";
        d.push_back(s);
        int j=0;
        for (int i=0;i<s.size();i++){
            if (s[i]==' '){
                num=s.substr(0,i+1);
                j=i+1;
            }
        }
        while(j<s.size()){
            string temp=num;
            if (s[j]=='.'){
                temp+=s.substr(j+1);
                d.push_back(temp);
                
            }
            j++;
        }
    }
    vector<string> subdomainVisits(vector<string>& c) {
        vector<string>r;
        vector<string>d;
        unordered_map<string,int>res;
        for(int i=0;i<c.size();i++){
            domain(r,c[i]);
        }
        for (int i=0;i<r.size();i++){
            int ind=r[i].find(' ');
            string num=r[i].substr(0,ind);
            string rem=r[i].substr(ind+1);
            if (res.find(rem)==res.end()){
                res[rem]=stoi(num);
            } else{
                res[rem]+=stoi(num);
            }
        }
        for (auto i:res){
            
            string tem=to_string(i.second);
            tem+=' ';
            tem+=i.first;
            d.push_back(tem);
        }
        return d;
    }
};