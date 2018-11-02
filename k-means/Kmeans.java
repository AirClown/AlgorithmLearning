import com.sun.tools.javac.Main;

import java.awt.*;

public class Kmeans {

    public static void main(String[] args) {
        System.out.print("Hello");

        Point[] points=new Point[1000];
        for (int i=0;i<points.length;i++){
            points[i]=new Point();
            points[i].x=(int)(points.length*Math.random());
            points[i].y=(int)(points.length*Math.random());
        }

        Point[] centre=Kmeans(4,points,100);

        for (int i=0;i<centre.length;i++){
            System.out.print("x:"+centre[i].x+",y:"+centre[i].y+"\n");
        }
    }

    //Kmeans算法
    //k:聚类数量
    //points:坐标数据
    //iteration:迭代计算次数
    //返回：聚类中心
    public static Point[] Kmeans(int k, Point[] points,int iteration){
        if (points.length<k) return null;

        //聚类中心
        Point[] centre=new Point[k];
        for(int i=0;i<centre.length;i++){
            centre[i]=points[i];
        }

        while (--iteration>0){
            //分组下标，每个数据对应聚类中心数组的下标
            int[] index=new int[points.length];

            //统计每组的数据数量
            int[] count=new int[centre.length];

            //分组
            for (int i=0;i<points.length;i++){
                //最小距离，-1代表没有初值
                float min=-1;

                //寻找最近的聚类中心
                for (int j=0;j<centre.length;j++){
                    float d=(float) Math.sqrt((centre[j].x-points[i].x)*(centre[j].x-points[i].x)+
                            (centre[j].y-points[i].y)*(centre[j].y-points[i].y));
                    if(min<0||d<min){
                        min=d;
                        index[i]=j;
                    }
                }

                ++count[index[i]];
            }

            //更新聚类中心
            for(int i=0;i<centre.length;i++){
                centre[i].x=0;
                centre[i].y=0;
            }

            for (int i=0;i<index.length;i++){
                centre[index[i]].x+=points[i].x;
                centre[index[i]].y+=points[i].y;
            }

            for(int i=0;i<centre.length;i++){
                if (count[i]==0) continue;
                centre[i].x/=count[i];
                centre[i].y/=count[i];
            }
        }

        return centre;
    }

}
