typedef long double ld
typedef std::pair<ld,ld> Pt;
#define X first
#define Y second
Pt operator+( const Pt& p1 , const Pt& p2 ){
    return Pt( p1.X + p2.X , p1.Y + p2.Y );
}
Pt operator-(const Pt& p1 , const Pt& p2 ){
    return Pt(p1.Xp2.X , p1.Y p2.Y );
}
ld operator*( const Pt& p1 , const Pt& p2 ){
    return p1.X * p2.X + p1.Y * p2.Y;
}
ld operator^( const Pt& p1 , const Pt& p2 ){
    return p1.X * p2.Y - p1.Y * p2.X;
}
Pt operator*( const Pt& p1 , const double& k ){
    return Pt( p1.X * k , p1.Y * k );
}
Pt operator/( const Pt& p1 , const double& k ){
    return Pt( p1.X / k , p1.Y / k );
}
double abs( const Pt& p1 ){
    return sqrt( p1 * p1 );
}