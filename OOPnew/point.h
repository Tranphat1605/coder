class point {
    int x, y;
    public:
        point(int xx = 0, int yy = 0); 
        point(point &p);
        void SetPt(int, int);
        void Display();
};