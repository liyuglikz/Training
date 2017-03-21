bool ClipsEllipSimple(double AAxis,double BAxis,double CAxis, //椭圆的三个轴长
     double x1,double y1,double z1, //直线的一个端点
     double x2,double y2,double z2,osg::Vec3d* out_pt1,osg::Vec3d* out_pt2) //直线的另一个端点
    {
        double ta,tb,tc; //参数方程的参数
        double delt; //判断一元二次方程是否有根,求交用
        double ASquare,BSquare,CSquare; //分别代表椭球三轴的平方
        ASquare=AAxis*AAxis;
        BSquare=BAxis*BAxis;
        CSquare=CAxis*CAxis;
        double A = (y2 -y1) / (x2 - x1);
        double B = (z2 -z1) / (x2 - x1);
        ta = BSquare * CSquare + A * A * ASquare * CSquare + B * B * ASquare * BSquare;
        tb = 2 * y1 * ASquare * CSquare * A - 2 * x1 * A * A * ASquare * CSquare + 2 * z1 * ASquare * BSquare * B - 2 * x1 * B * B * ASquare * BSquare;
        tc = ASquare * CSquare* y1 * y1 - 2 * y1 * ASquare * CSquare * A * x1 + A * A * x1 * x1 * ASquare * CSquare +
                    ASquare * BSquare * z1 * z1 - 2 * z1 * ASquare * BSquare * B * x1 + B * B * x1 * x1 * ASquare * BSquare - ASquare * BSquare * CSquare;
        delt = tb*tb - 4*ta*tc;
        double t1,t2;
        if(delt>=0)
        {
            t1=(-tb+sqrt(delt))/(2*ta);
            t2=(-tb-sqrt(delt))/(2*ta);
            double x =t1;
            double y = y1 + A * (x - x1);
            double z = z1 + B * (x - x1);
            *out_pt1 = osg::Vec3d(x,y,z);
            x =t2;
            y = y1 + A * (x - x1);
            z = z1 + B * (x - x1);
            *out_pt2 = osg::Vec3d(x,y,z);
            return true;
        }   
        else
            return false;
    } 
