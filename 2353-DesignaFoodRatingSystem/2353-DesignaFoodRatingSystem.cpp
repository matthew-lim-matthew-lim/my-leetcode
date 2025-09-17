// Last updated: 9/17/2025, 8:34:03 PM
/* 
Cuisine -> Multiple foods
Food -> Rating

Can change Rating using Food.

Order on Rating then Food name.
 */
class FoodRatings {
private:
    struct PairCompare {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) const {
            if (a.first == b.first) {
                return a.second > b.second;  
            }
            return a.first < b.first;
        }
    };

    // { Food, { Rating, Cuisine }}
    unordered_map<string, pair<int, string>> foodMap;

    // { Cuisine, Set{ Rating, Food }}
    unordered_map<string, set<pair<int, string>, PairCompare>> cuisineMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodMap[foods[i]] = { ratings[i], cuisines[i] };
            cuisineMap[cuisines[i]].insert({ ratings[i], foods[i] });
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodMap[food].first;
        string cuisine = foodMap[food].second;
        foodMap[food].first = newRating;

        cuisineMap[cuisine].erase({ oldRating, food });
        cuisineMap[cuisine].insert({ newRating, food });
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].rbegin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */