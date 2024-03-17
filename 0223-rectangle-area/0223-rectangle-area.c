int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int ar1=(ax2-ax1)*(ay2-ay1);
    int ar2=(bx2-bx1)*(by2-by1);
    int xmin,xmax,ymin,ymax,xov,yov;
    if (ax2<bx2){
        xmin=ax2;
    }
    else{
        xmin=bx2;
    }
    if (ax1<bx1){
        xmax=bx1;
    }
    else{
        xmax=ax1;
    }
    if (ay2<by2){
        ymin=ay2;
    }
    else{
        ymin=by2;
    }
    if (ay1<by1){
        ymax=by1;
    }
    else{
        ymax=ay1;
    }
    if ((xmin-xmax)>0){
        xov=xmin-xmax;
    }
    else{
        xov=0;
    }
    if ((ymin-ymax)>0){
        yov=ymin-ymax;
    }
    else{
        yov=0;
    }
    int aov=xov*yov;
    return ar1+ar2-aov;
}