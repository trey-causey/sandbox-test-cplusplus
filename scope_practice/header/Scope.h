//
// Created by TJC on 10/2/2020.
//

#ifndef SCOPE_PRACTICE_SCOPE_H
#define SCOPE_PRACTICE_SCOPE_H

namespace nsa {

    class Scope
    {
    private:
      int x{12};
      int y{34};
    public:
       static int fAdd(int a, int b);
       int fMultiply(int g, int h);
    };
}



#endif //SCOPE_PRACTICE_SCOPE_H
