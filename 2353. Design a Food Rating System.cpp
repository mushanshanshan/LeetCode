class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> cui_to_rank;
    unordered_map<string, string> food_to_cui;
    unordered_map<string, int> food_to_rank;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); i++) {
            food_to_cui[foods[i]] = cuisines[i];
            food_to_rank[foods[i]] = -ratings[i];
            cui_to_rank[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        cui_to_rank[food_to_cui[food]].erase({food_to_rank[food], food});
        food_to_rank[food] = -newRating;
        cui_to_rank[food_to_cui[food]].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cui_to_rank[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */