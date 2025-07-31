class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 4 types of directiona are there 
        // -2 so if n -> w ->s->e
        // -1 so of m->e->s->w


        bool n=true;
        bool e=false;
        bool w =false;
        bool s =false;
         //if n or s we have to move y else x n-> y++ else y-- and east x++/ x--

         map<pair<int,int>,int> blocked;
         int maxx=0;
         // to calculate the max distance from the origin 

         for(auto vec:obstacles){
            blocked[{vec[0],vec[1]}]++;
         }


         // if no is not -2 nor -1 , which means its the magnitude move in that direction acc to the flag
         int x =0;
         int y=0; 

         for(int el :commands){
            if(el!=-1 && el!=-2){
                // no chnage in direction
                int mag =el;// this much distance we have to move our x/y
                for(int i=0;i<mag;i++){
                    if(n){
                        y++;
                        if(blocked.count({x,y})) {
                            y--;
                            // on that direction only it will break 
                            break;
                        }
                       
                    }
                    else if(s){
                        y--;
                        if(blocked.count({x,y})) {
                            y++;
                            // on that direction only it will break 
                            break;
                        }
                       
                    }
                    else if(e){
                        x++;
                        if(blocked.count({x,y})) {
                            x--;
                            // on that direction only it will break 
                            break;
                        }
                       
                    }
                    else{
                        x--;
                        if(blocked.count({x,y})) {
                            x++;
                            // on that direction only it will break 
                            break;
                        }

                   
                    }
                     maxx=max(maxx,((x*x)+(y*y)));
                      
                }
            }
                else{
                    if(el==-1){
                        if(n){
                            n=false;
                            e=true;
                        }
                        else if(s){
                            s=false;
                            w=true;
                        }
                        else if(e){
                            s=true;
                            e=false;
                        }
                        else if(w){
                            n=true;
                            w=false;
                        }
                    }
                    else if(el==-2){
                        if(n){
                            n=false;
                            w=true;
                        }
                        else if(s){
                            s=false;
                            e=true;
                        }
                        else if(e){
                            n=true;
                            e=false;
                        }
                        else if(w){
                            s=true;
                            w=false;
                        }
                    }
                }
            }

         return maxx;
        
    }
};