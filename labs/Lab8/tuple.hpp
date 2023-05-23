#ifndef TUPLE_HPP
#define TUPLE_HPP

template <class T>
class Tuple {

    private:
        T data[2];

        //
        // Only having this so we have dynamic memory.
        //
        T* extra;

    public:

        //
        // Default Constructor
        //
        Tuple(){
            extra = NULL;
            return;
        }

        //
        // Copy Constructor
        //
        Tuple(const Tuple<T> &t) {

            //
            // Not copying the pointer since it is just an extra variable I
            // added for demonstration purposes.
            //

            data[0] = t.data[0];
            data[1] = t.data[1];
            return;
        }

        //
        // Non-default Constructor
        //
        Tuple(T data_0, T data_1) {
            data[0] = data_0;
            data[1] = data_1;
            extra = new T[100];
            return;
        }


        //
        // Getters
        //
        T get_d0() {
            return data[0];
        }

        T get_d1() {
            return data[1];
        }


        //
        // Destructor
        //
        ~Tuple() {
            delete [] extra;
            return;
        }


        //
        // Setters
        //
        void set_d0(T n_d0) {
            data[0] = n_d0;
            return;
        }

        void set_d1(T n_d1) {
            data[1] = n_d1;
            return;
        }


        //
        // Operator Overload
        //
        void operator= (const Tuple<T> &t) {

            //
            // Not copying the pointer since it is just an extra variable I
            // added for demonstration purposes.
            //

            data[0] = t.data[0];
            data[1] = t.data[1];
            return;
        }
};
#endif
