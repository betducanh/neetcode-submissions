class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ourStack;
        for (int asteroid : asteroids) {
            if (ourStack.empty() || asteroid > 0) {
                ourStack.push_back(asteroid);
                continue;
            }
            if (asteroid < 0) {
                bool broken = false;
                while (!broken && !ourStack.empty() && ourStack[ourStack.size()-1] > 0) {
                    if (abs(asteroid) < ourStack[ourStack.size()-1]) broken = true;
                    else if (abs(asteroid) == ourStack[ourStack.size()-1]) {
                        broken = true;
                        ourStack.pop_back();
                    }
                    else ourStack.pop_back();
                }
                if (!broken) ourStack.push_back(asteroid);
            }
        }
        return ourStack; 
    }
};