class Drop {      
    float yVelocity;
    float height;

public:
    float x, y;  
    Drop();

    void fall();
    void show();
    void resetDrop();
    bool isInsideTank();
};