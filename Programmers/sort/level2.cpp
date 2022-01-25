bool compare(string s1,string s2){
    if(s1[0]!=s2[0]){
        return s1>s2;
    }
    else if(s1.length()!=s2.length()){
        if(s1.length()<s2.length()){
            for(int i=1;i<s2.length();i++){
                    if(s1[s1.size()-i]<s2[i]){
                        return false;
                    }
                    else if(s1[s1.size()-i]>s2[i]){
                        return true;
                    }
            }
            if(s1[0]>s2[1]){
                return false;
            }
            else{
              
                return true;
            }
            
        }
        else if(s1.length()>s2.length()){
            for(int i=1;i<s1.length();i++){
                    if(s1[i]>s2[s2.size()-i]){
                        return true;
                    }
                    else if(s1[i]<s2[s2.size()-i]){
                        return false;
                    }
            }
             if(s1[1]<s2[0]){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
    else{ // s1.lengh==s2.lengh 
        return s1>s2;
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> string_numbers;

    for(auto num : numbers)
        string_numbers.push_back(to_string(num));

    sort(string_numbers.begin(),string_numbers.end(),compare);

    for(auto str: string_numbers)
    cout<<str<<'\n';

    for(auto str : string_numbers)
         answer+=str;
    
    for(auto a : answer){
        if(a!='0'){
            return answer;
        }

    }
    return "0";
}

int main(){
    //string answer=solution({31,343,323,32,332,301,1000, 300,30,35,330,3, 100,10,5, 9,01});
    string answer=solution({45,454,123,12,132,13,32,43,434,4,435,433,432,453,45,1000,10,100,1,330,3});
    //string answer=solution({1,0,1,0});
    cout<<answer<<'\n';
    
}