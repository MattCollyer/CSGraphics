#ifndef Ray_H
#define Ray_H
class Ray{


        private:

                Tuple origin;
                Tuple direction;

        public:

                Ray(Tuple o, Tuple d);
                Tuple getOrigin() const;
                Tuple getDirection() const;
                Tuple pointAtT(double t);
};
#endif
