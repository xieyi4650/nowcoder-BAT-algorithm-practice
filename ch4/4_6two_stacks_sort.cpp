class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        vector<int> help;
        help.push_back(numbers.back());
        numbers.pop_back();
        while(!numbers.empty()){
            int curr = numbers.back();
            numbers.pop_back();
            if(curr <= help.back()){
                help.push_back(curr);
            }else{
                do{
                    numbers.push_back(help.back());
                    help.pop_back();
                }while(help.back() < curr && !help.empty());
                help.push_back(curr);
            }
        }
        return help;
    }
};
