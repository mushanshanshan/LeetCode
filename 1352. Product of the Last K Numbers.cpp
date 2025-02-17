class ProductOfNumbers {
    private:
        vector<long long> mul = {1};
    
    public:
        ProductOfNumbers() {
        }
        
        void add(int num) {
            if (num == 0) mul = {1};
            else mul.push_back(num * mul[mul.size() - 1]);
        }
        
        int getProduct(int k) {
            return k >= mul.size() ? 0: mul[mul.size() - 1] / mul[mul.size() - 1 - k];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */