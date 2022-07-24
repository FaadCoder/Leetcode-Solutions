class FoodRatings {
    unordered_map<string,set<pair<int,string>>> cuisineToRatingFoodMap;
    unordered_map<string,int> foodToRatingMap;
    unordered_map<string,string> foodToCuisineMap;
    
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    
        for(int idx = 0; idx<foods.size(); idx++)
        {
            string food = foods[idx];
            string cuisine = cuisines[idx];
            int rating = ratings[idx];
            
            cuisineToRatingFoodMap[cuisine].insert({-rating,food});
            foodToRatingMap[food] = rating;
            foodToCuisineMap[food] = cuisine;
        }
        
        
    }
    
    void changeRating(string food, int newRating) {
        
        string cuisine = foodToCuisineMap[food];
        int rating = foodToRatingMap[food];
        
        auto it = cuisineToRatingFoodMap[cuisine].find({-rating,food});
        
        if(it!=cuisineToRatingFoodMap[cuisine].end())
        cuisineToRatingFoodMap[cuisine].erase(it);
        
        foodToRatingMap[food] = newRating;
        cuisineToRatingFoodMap[cuisine].insert({-newRating,food});
        
    }
    
    string highestRated(string cuisine) {
        return (*cuisineToRatingFoodMap[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */