// Last updated: 3/21/2025, 12:53:11 PM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Or just use a set for the supplies. 
        // For each recipe, does all the ingredients appear in the set. 
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());

        unordered_set<string> resSet;

        int prevSize = -1;
        while (prevSize != resSet.size()) {
            prevSize = resSet.size();

            for (int i = 0; i < ingredients.size(); i++) {
                if (resSet.contains(recipes[i])) {
                    continue;
                }
                bool valid = true;
                // Go through every recipe
                for (int j = 0; j < ingredients[i].size(); j++) {
                    // Go through every ingredient
                    if (!suppliesSet.contains(ingredients[i][j]) && !resSet.contains(ingredients[i][j])) {
                        valid = false;
                        break;
                    }
                }
                if (valid == true) {
                    resSet.insert(recipes[i]);
                }
            }
        }


        return vector<string>(resSet.begin(), resSet.end());
    }
};