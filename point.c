#include<stdio.h>
#include<math.h>

typedef struct
{
   float x;
   float y;
}POINT;

float getX(POINT point){
    return point.x;
}

float getY(POINT point){
    return point.y;
}

float get_theta(POINT point){
    float theta;
    theta = atan2(point.y , point.x);
    return theta;
}

float get_length(POINT point){
    float length;
    length = sqrt(point.x * point.x + point.y * point.y);
    return length;
}

void setX(POINT* p, float x_change){
    (*p).x = x_change;
}


void setY(POINT* p, float y_change){
    (*p).y = y_change;
}

void setL(POINT* p, float l_change){
    float theta = get_theta((*p));
    (*p).x = l_change * cos(theta);
    (*p).y = l_change * sin(theta);
}
void setA(POINT *p, float theta_change){
    float length = get_length((*p));
    (*p).x = length * cos(theta_change);
    (*p).y = length * sin(theta_change);
}

int main(){
    POINT point1;
    printf("请输入点的横纵坐标，以空格隔开\n");
    scanf("%f %f", &point1.x, &point1.y);
    printf("点的横坐标是%.3f， 纵坐标是%.3f， 极坐标极径是%.3f， 极角是%.3f\n",getX(point1),getY(point1),get_length(point1),get_theta(point1));

    printf("是否进行修改？（输入数字）\n1横坐标 2纵坐标 3极径 4极角 5不修改\n");
    int tmp;
    float change;
    scanf("%d",&tmp);
    if(tmp ==1){
        printf("输入修改后的横坐标\n");
        scanf("%f", &change);
        setX(&point1,change);
        printf("点的横坐标是%.3f， 纵坐标是%.3f， 极坐标极径是%.3f， 极角是%.3f\n",getX(point1),getY(point1),get_length(point1),get_theta(point1));
    }

    else if(tmp ==2){
        printf("输入修改后的纵坐标\n");
        scanf("%f", &change);
        setY(&point1, change);
        printf("点的横坐标是%.3f， 纵坐标是%.3f， 极坐标极径是%.3f， 极角是%.3f\n",getX(point1),getY(point1),get_length(point1),get_theta(point1));
    }
    
    else if(tmp ==3){
        printf("输入修改后的极径\n");
        scanf("%f", &change);
        setL(&point1, change);
        printf("点的横坐标是%.3f， 纵坐标是%.3f， 极坐标极径是%.3f， 极角是%.3f\n",getX(point1),getY(point1),get_length(point1),get_theta(point1));
    }
    
    else if(tmp ==4){
        printf("输入修改后的极角\n");
        scanf("%f", &change);
        setA(&point1, change);
        printf("点的横坐标是%.3f， 纵坐标是%.3f， 极坐标极径是%.3f， 极角是%.3f\n",getX(point1),getY(point1),get_length(point1),get_theta(point1));
    }
    
    return 0;
}