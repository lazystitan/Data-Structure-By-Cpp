//
// Created by Riton on 2019/11/12.
//

/*
 *                    Base
 *                      |
 *                      |
 *        +-------------+-------------+
 *        |             |             |
 *   MidPrivate    MidProtected    MidPublic
 */

#include <iostream>

using namespace std;

class Base {
    friend void base_friend_func(Base &b);
private:
    int _base_private_data = 1;
    virtual void virtual_action_private() {
        cout << "Base virtual private action" << endl;
    }
    void action_private() {
        cout << "Base private action" << endl;
    }

protected:
    int _base_protected_data = 2;
    virtual void virtual_action_protected() {
        cout << "Base virtual protected action" << endl;
    }
    void action_protected() {
        cout << "Base protected action" << endl;
    }

public:
    int _base_public_data = 3;
    virtual void virtual_action_public() {
        cout << "Base virtual public action" << endl;
    }
    void action_public() {
        cout << "Base public action" << endl;
    }
};

void base_friend_func(Base &b) {
    cout << b._base_private_data << endl;
    cout << b._base_protected_data << endl;
    cout << b._base_public_data << endl;
}

class MidPublic : public Base {
    friend void mid_pub_friend_function(MidPublic &m);
private:
    int _mid_pub_private_data = 211;
    void virtual_action_private() override {
        cout << "mid pub virtual private action" << endl;
    }
    void action_private() {
        cout << "mid pub private aciton" << endl;
    }

protected:
    int _mid_pub_protect_data = 212;
    void virtual_action_protected() override {
        cout << "mid pub virtual private action" << endl;
    }
    void action_protected() {
        cout << "mid pub private aciton" << endl;
    }

public:
    int _mid_pub_public_data = 213;
    void virtual_action_public() override {
        cout << "mid pub virtual private action" << endl;
    }
    void action_public() {
        cout << "mid pub private aciton" << endl;
    }
};

void mid_pub_friend_function(MidPublic &m) {
//    friend function of MidPub which public derived from base cannot access base's private members
//    cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
    cout << m._mid_pub_private_data << endl;
    cout << m._mid_pub_protect_data << endl;
    cout << m._mid_pub_public_data << endl;
}

class MidProtect : protected Base {
    friend void mid_pro_friend_function(MidProtect &m);
private:
    int _mid_pro_private_data = 221;
    void virtual_action_private() override {
        cout << "mid pro virtual private action" << endl;
    }
    void action_private() {
        cout << "mid pro private aciton" << endl;
    }

protected:
    int _mid_pro_protect_data = 222;
    void virtual_action_protected() override {
        cout << "mid pro virtual private action" << endl;
    }
    void action_protected() {
        cout << "mid pro private aciton" << endl;
    }

public:
    int _mid_pro_public_data = 223;
    void virtual_action_public() override {
        cout << "mid pro virtual private action" << endl;
    }
    void action_public() {
        cout << "mid pro private aciton" << endl;
    }
};

void mid_pro_friend_function(MidProtect &m) {
//    friend function of MidPro which protected derived from base cannot access base's private members
//    cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
    cout << m._mid_pro_private_data << endl;
    cout << m._mid_pro_protect_data << endl;
    cout << m._mid_pro_public_data << endl;
}

class MidPrivate : private Base {
    friend void mid_pri_friend_function(MidPrivate &m);
private:
    int _mid_pri_private_data = 231;
    void virtual_action_private() override {
        cout << "mid pri virtual private action" << endl;
    }
    void action_private() {
        cout << "mid pri private aciton" << endl;
    }

protected:
    int _mid_pri_protect_data = 232;
    void virtual_action_protected() override {
        cout << "mid pri virtual private action" << endl;
    }
    void action_protected() {
        cout << "mid pri private aciton" << endl;
    }

public:
    int _mid_pri_public_data = 233;
    void virtual_action_public() override {
        cout << "mid pri virtual private action" << endl;
    }
    void action_public() {
        cout << "mid pri private aciton" << endl;
    }
};

void mid_pri_friend_function(MidPrivate &m) {
//    friend function of MidPro which protected derived from base cannot access base's private members
//    cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
    cout << m._mid_pri_private_data << endl;
    cout << m._mid_pri_protect_data << endl;
    cout << m._mid_pri_public_data << endl;
}

class TopPubMidPub : public MidPublic {
    friend void top_pub_mid_pub_firend_func(TopPubMidPub &m);
private:
    int _top_pub_mid_pub_private_data = 311;
    void virtual_action_private() override {
        cout << "top pub mid pub virtual private action" << endl;
    }
    void action_private() {
        cout << "top pub mid pub private aciton" << endl;
    }

protected:
    int _top_pub_mid_pub_protect_data = 312;
    void virtual_action_protected() override {
        cout << "top pub mid pub virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pub mid pub private aciton" << endl;
    }

public:
    int _top_pub_mid_pub_public_data = 313;
    void virtual_action_public() override {
        cout << "top pub mid pub virtual private action" << endl;
    }
    void action_public() {
        cout << "top pub mid pub private aciton" << endl;
    }
};

void top_pub_mid_pub_firend_func(TopPubMidPub &m) {
//    cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
    cout << m._mid_pub_protect_data << endl;
    cout << m._mid_pub_public_data << endl;
    cout << m._top_pub_mid_pub_private_data << endl;
    cout << m._top_pub_mid_pub_protect_data << endl;
    cout << m._top_pub_mid_pub_public_data << endl;
}

class TopProMidPub : protected MidPublic {
    friend void top_pro_mid_pub_firend_func(TopProMidPub &m);
private:
    int _top_pro_mid_pub_private_data = 321;
    void virtual_action_private() override {
        cout << "top pro mid pub virtual private action" << endl;
    }
    void action_private() {
        cout << "top pro mid pub private aciton" << endl;
    }

protected:
    int _top_pro_mid_pub_protect_data = 322;
    void virtual_action_protected() override {
        cout << "top pro mid pub virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pro mid pub private aciton" << endl;
    }

public:
    int _top_pro_mid_pub_public_data = 323;
    void virtual_action_public() override {
        cout << "top pro mid pub virtual private action" << endl;
    }
    void action_public() {
        cout << "top pro mid pub private aciton" << endl;
    }
};

void top_pro_mid_pub_firend_func(TopProMidPub &m) {
//    cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
    cout << m._mid_pub_protect_data << endl;
    cout << m._mid_pub_public_data << endl;
    cout << m._top_pro_mid_pub_private_data << endl;
    cout << m._top_pro_mid_pub_protect_data << endl;
    cout << m._top_pro_mid_pub_public_data << endl;
}

class TopPriMidPub : private MidPublic {
    friend void top_pri_mid_pub_firend_func(TopPriMidPub &m);
private:
    int _top_pri_mid_pub_private_data =2331;
    void virtual_action_private() override {
        cout << "top pri mid pub virtual private action" << endl;
    }
    void action_private() {
        cout << "top pri mid pub private aciton" << endl;
    }

protected:
    int _top_pri_mid_pub_protect_data = 332;
    void virtual_action_protected() override {
        cout << "top pri mid pub virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pri mid pub private aciton" << endl;
    }

public:
    int _top_pri_mid_pub_public_data = 333;
    void virtual_action_public() override {
        cout << "top pri mid pub virtual private action" << endl;
    }
    void action_public() {
        cout << "top pri mid pub private aciton" << endl;
    }
};

void top_pri_mid_pub_firend_func(TopPriMidPub &m) {
//    cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
    cout << m._mid_pub_protect_data << endl;
    cout << m._mid_pub_public_data << endl;
    cout << m._top_pri_mid_pub_private_data << endl;
    cout << m._top_pri_mid_pub_protect_data << endl;
    cout << m._top_pri_mid_pub_public_data << endl;
}

class TopPubMidPro : public MidProtect {
    friend void top_pub_mid_pro_firend_func(TopPubMidPro &m);
private:
    int _top_pub_mid_pro_private_data =2331;
    void virtual_action_private() override {
        cout << "top pub mid pro virtual private action" << endl;
    }
    void action_private() {
        cout << "top pub mid pro private aciton" << endl;
    }

protected:
    int _top_pub_mid_pro_protect_data = 332;
    void virtual_action_protected() override {
        cout << "top pub mid pro virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pub mid pro private aciton" << endl;
    }

public:
    int _top_pub_mid_pro_public_data = 333;
    void virtual_action_public() override {
        cout << "top pub mid pro virtual private action" << endl;
    }
    void action_public() {
        cout << "top pub mid pro private aciton" << endl;
    }
};

void top_pub_mid_pro_firend_func(TopPubMidPro &m) {
    //    cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
    cout << m._mid_pro_protect_data << endl;
    cout << m._mid_pro_public_data << endl;
    cout << m._top_pub_mid_pro_private_data << endl;
    cout << m._top_pub_mid_pro_protect_data << endl;
    cout << m._top_pub_mid_pro_public_data << endl;
}

class TopProMidPro : protected MidProtect {
    friend void top_pro_mid_pro_firend_func(TopProMidPro &m);
private:
    int _top_pro_mid_pro_private_data =2331;
    void virtual_action_private() override {
        cout << "top pro mid pro virtual private action" << endl;
    }
    void action_private() {
        cout << "top pro mid pro private aciton" << endl;
    }

protected:
    int _top_pro_mid_pro_protect_data = 332;
    void virtual_action_protected() override {
        cout << "top pro mid pro virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pro mid pro private aciton" << endl;
    }

public:
    int _top_pro_mid_pro_public_data = 333;
    void virtual_action_public() override {
        cout << "top pro mid pro virtual private action" << endl;
    }
    void action_public() {
        cout << "top pro mid pro private aciton" << endl;
    }
};

void top_pro_mid_pro_firend_func(TopProMidPro &m) {
//        cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
    cout << m._mid_pro_protect_data << endl;
    cout << m._mid_pro_public_data << endl;
    cout << m._top_pro_mid_pro_private_data << endl;
    cout << m._top_pro_mid_pro_protect_data << endl;
    cout << m._top_pro_mid_pro_public_data << endl;
}

class TopPriMidPro : private MidProtect {
    friend void top_pri_mid_pro_firend_func(TopPriMidPro &m);
private:
    int _top_pri_mid_pro_private_data =2331;
    void virtual_action_private() override {
        cout << "top pri mid pro virtual private action" << endl;
    }
    void action_private() {
        cout << "top pri mid pro private aciton" << endl;
    }

protected:
    int _top_pri_mid_pro_protect_data = 332;
    void virtual_action_protected() override {
        cout << "top pri mid pro virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pri mid pro private aciton" << endl;
    }

public:
    int _top_pri_mid_pro_public_data = 333;
    void virtual_action_public() override {
        cout << "top pri mid pro virtual private action" << endl;
    }
    void action_public() {
        cout << "top pri mid pro private aciton" << endl;
    }
};

void top_pri_mid_pro_firend_func(TopPriMidPro &m) {
//        cout << m._base_private_data << endl;
    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
    cout << m._mid_pro_protect_data << endl;
    cout << m._mid_pro_public_data << endl;
    cout << m._top_pri_mid_pro_private_data << endl;
    cout << m._top_pri_mid_pro_protect_data << endl;
    cout << m._top_pri_mid_pro_public_data << endl;
}

class TopPubMidPri : public MidPrivate {
    friend void top_pub_mid_pri_firend_func(TopPubMidPri &m);
private:
    int _top_pub_mid_pri_private_data =2331;
    void virtual_action_private() override {
        cout << "top pub mid pri virtual private action" << endl;
    }
    void action_private() {
        cout << "top pub mid pri private aciton" << endl;
    }

protected:
    int _top_pub_mid_pri_protect_data = 332;
    void virtual_action_protected() override {
        cout << "top pub mid pri virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pub mid pri private aciton" << endl;
    }

public:
    int _top_pub_mid_pri_public_data = 333;
    void virtual_action_public() override {
        cout << "top pub mid pri virtual private action" << endl;
    }
    void action_public() {
        cout << "top pub mid pri private aciton" << endl;
    }
};

void top_pub_mid_pri_firend_func(TopPubMidPri &m) {
//    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
//    cout << m._base_public_data << endl;
//    cout << m._mid_pri_private_data << endl;
    cout << m._mid_pri_protect_data << endl;
    cout << m._mid_pri_public_data << endl;
    cout << m._top_pub_mid_pri_private_data << endl;
    cout << m._top_pub_mid_pri_protect_data << endl;
    cout << m._top_pub_mid_pri_public_data << endl;
}

class TopProMidPri : protected MidPrivate {
    friend void top_pro_mid_pri_firend_func(TopProMidPri &m);
private:
    int _top_pro_mid_pri_private_data =2331;
    void virtual_action_private() override {
        cout << "top pro mid pri virtual private action" << endl;
    }
    void action_private() {
        cout << "top pro mid pri private aciton" << endl;
    }

protected:
    int _top_pro_mid_pri_protect_data = 332;
    void virtual_action_protected() override {
        cout << "top pro mid pri virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pro mid pri private aciton" << endl;
    }

public:
    int _top_pro_mid_pri_public_data = 333;
    void virtual_action_public() override {
        cout << "top pro mid pri virtual private action" << endl;
    }
    void action_public() {
        cout << "top pro mid pri private aciton" << endl;
    }
};

void top_pro_mid_pri_firend_func(TopProMidPri &m) {
//    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
//    cout << m._base_public_data << endl;
//    cout << m._mid_pri_private_data << endl;
    cout << m._mid_pri_protect_data << endl;
    cout << m._mid_pri_public_data << endl;
    cout << m._top_pro_mid_pri_private_data << endl;
    cout << m._top_pro_mid_pri_protect_data << endl;
    cout << m._top_pro_mid_pri_public_data << endl;
}

class TopPriMidPri : private MidPrivate {
    friend void top_pri_mid_pri_firend_func(TopPriMidPri &m);
private:
    int _top_pri_mid_pri_private_data =2331;
    void virtual_action_private() override {
        cout << "top pri mid pri virtual private action" << endl;
    }
    void action_private() {
        cout << "top pri mid pri private aciton" << endl;
    }

protected:
    int _top_pri_mid_pri_protect_data = 332;
    void virtual_action_protected() override {
        cout << "top pri mid pri virtual private action" << endl;
    }
    void action_protected() {
        cout << "top pri mid pri private aciton" << endl;
    }

public:
    int _top_pri_mid_pri_public_data = 333;
    void virtual_action_public() override {
        cout << "top pri mid pri virtual private action" << endl;
    }
    void action_public() {
        cout << "top pri mid pri private aciton" << endl;
    }
};

void top_pri_mid_pri_firend_func(TopPriMidPri &m) {
//        cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
//    cout << m._base_public_data << endl;
//    cout << m._mid_pri_private_data << endl;
    cout << m._mid_pri_protect_data << endl;
    cout << m._mid_pri_public_data << endl;
    cout << m._top_pri_mid_pri_private_data << endl;
    cout << m._top_pri_mid_pri_protect_data << endl;
    cout << m._top_pri_mid_pri_public_data << endl;
}

void base_test() {
    //user can only access base public members
    auto b  = Base();
//    cout << b._base_private_data << endl;
//    cout << b._base_protected_data << endl;
    cout << b._base_public_data << endl;
//    b.virtual_action_private();
//    b.virtual_action_protected()
    b.virtual_action_public();
//    b.action_private();
//    b.action_protected();
    b.action_public();

    //base's friend can access Base's all members
    base_friend_func(b);
}

void mid_public_test() {
    auto m = MidPublic();
    mid_pub_friend_function( m);
//    user of MidPub cannot access MidPub's and Base's non-public members
//    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
//    cout << m._mid_pub_protect_data << endl;
    cout << m._mid_pub_public_data << endl;

    Base *b = &m;

}

void mid_protected_test() {
    MidProtect m;
    mid_pro_friend_function(m);
//    user of can only access MidPro's public members
//    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
//    cout << m._base_public_data << endl;
//    cout << m._mid_pro_private_data << endl;
//    cout << m._mid_pro_protect_data << endl;
    cout << m._mid_pro_public_data << endl;

//    Base *b = &m;
//    cannot cast
}

void mid_private_test() {
    auto m = MidPrivate();
    mid_pri_friend_function(m);
//    user of can only access MidPri's public members
//    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
//    cout << m._base_public_data << endl;
//    cout << m._mid_pri_private_data << endl;
//    cout << m._mid_pri_protect_data << endl;
    cout << m._mid_pri_public_data << endl;

//    Base *b = &m;
//    cannot cast
}

void top_pub_mid_pub_test() {
    auto m = TopPubMidPub();
    top_pub_mid_pub_firend_func(m);
    //    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
//    cout << m._mid_pub_protect_data << endl;
    cout << m._mid_pub_public_data << endl;
//    cout << m._top_pub_mid_pub_private_data << endl;
//    cout << m._top_pub_mid_pub_protect_data << endl;
    cout << m._top_pub_mid_pub_public_data << endl;
    MidPublic *mp = &m;
    Base *b = &m;

}

void top_pro_mid_pub_test() {
    auto m = TopProMidPub();
    top_pro_mid_pub_firend_func(m);
//    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
//    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
//    cout << m._mid_pub_protect_data << endl;
//    cout << m._mid_pub_public_data << endl;
//    cout << m._top_pro_mid_pub_private_data << endl;
//    cout << m._top_pro_mid_pub_protect_data << endl;
    cout << m._top_pro_mid_pub_public_data << endl;
//    MidPublic *mp = &m;
//    Base *b = &m;

}

void top_pri_mid_pub_test() {
    auto m = TopPriMidPub();
    top_pri_mid_pub_firend_func(m);
//    cout << m._base_private_data << endl;
//    cout << m._base_protected_data << endl;
//    cout << m._base_public_data << endl;
//    cout << m._mid_pub_private_data << endl;
//    cout << m._mid_pub_protect_data << endl;
//    cout << m._mid_pub_public_data << endl;
//    cout << m._top_pri_mid_pub_private_data << endl;
//    cout << m._top_pri_mid_pub_protect_data << endl;
    cout << m._top_pri_mid_pub_public_data << endl;
//    MidPublic *mp = &m;
//    Base *b = &m;

}

void top_pub_mid_pro_test() {
    auto t = TopPubMidPro();
    top_pub_mid_pro_firend_func(t);
    //    cout << t._base_private_data << endl;
//    cout << t._base_protected_data << endl;
//    cout << t._base_public_data << endl;
//    cout << t._mid_pro_private_data << endl;
//    cout << t._mid_pro_protect_data << endl;
    cout << t._mid_pro_public_data << endl;
//    cout << t._top_pub_mid_pro_private_data << endl;
//    cout << t._top_pub_mid_pro_protect_data << endl;
    cout << t._top_pub_mid_pro_public_data << endl;
    MidProtect *mp = &t;
//    Base *b = &t;
}

void top_pro_mid_pro_test() {
    auto t = TopProMidPro();
    top_pro_mid_pro_firend_func(t);
//    cout << t._base_private_data << endl;
//    cout << t._base_protected_data << endl;
//    cout << t._base_public_data << endl;
//    cout << t._mid_pro_private_data << endl;
//    cout << t._mid_pro_protect_data << endl;
//    cout << t._mid_pro_public_data << endl;
//    cout << t._top_pro_mid_pro_private_data << endl;
//    cout << t._top_pro_mid_pro_protect_data << endl;
    cout << t._top_pro_mid_pro_public_data << endl;
//    MidProtect *mp = &t;
//    Base *b = &t;
}

void top_pri_mid_pro_test() {
    auto t = TopPriMidPro();
    top_pri_mid_pro_firend_func(t);
//    cout << t._base_private_data << endl;
//    cout << t._base_protected_data << endl;
//    cout << t._base_public_data << endl;
//    cout << t._mid_pro_private_data << endl;
//    cout << t._mid_pro_protect_data << endl;
//    cout << t._mid_pro_public_data << endl;
//    cout << t._top_pri_mid_pro_private_data << endl;
//    cout << t._top_pri_mid_pro_protect_data << endl;
    cout << t._top_pri_mid_pro_public_data << endl;
//    MidProtect *mp = &t;
//    Base *b = &t;
}

void top_pub_mid_pri_test() {
    auto t = TopPubMidPri();
    top_pub_mid_pri_firend_func(t);
//    cout << t._base_private_data << endl;
//    cout << t._base_protected_data << endl;
//    cout << t._base_public_data << endl;
//    cout << t._mid_pri_private_data << endl;
//    cout << t._mid_pri_protect_data << endl;
    cout << t._mid_pri_public_data << endl;
//    cout << t._top_pub_mid_pri_private_data << endl;
//    cout << t._top_pub_mid_pri_protect_data << endl;
    cout << t._top_pub_mid_pri_public_data << endl;
    MidPrivate *mp = &t;
//    Base *b = &t;
}

void top_pro_mid_pri_test() {
    auto t = TopProMidPri();
    top_pro_mid_pri_firend_func(t);
//    cout << t._base_private_data << endl;
//    cout << t._base_protected_data << endl;
//    cout << t._base_public_data << endl;
//    cout << t._mid_pri_private_data << endl;
//    cout << t._mid_pri_protect_data << endl;
//    cout << t._mid_pri_public_data << endl;
//    cout << t._top_pro_mid_pri_private_data << endl;
//    cout << t._top_pro_mid_pri_protect_data << endl;
    cout << t._top_pro_mid_pri_public_data << endl;
//    MidProtect *mp = &t;
//    Base *b = &t;
}

void top_pri_mid_pri_test() {
    auto t = TopPriMidPri();
    top_pri_mid_pri_firend_func(t);
//    cout << t._base_private_data << endl;
//    cout << t._base_protected_data << endl;
//    cout << t._base_public_data << endl;
//    cout << t._mid_pri_private_data << endl;
//    cout << t._mid_pri_protect_data << endl;
//    cout << t._mid_pri_public_data << endl;
//    cout << t._top_pri_mid_pri_private_data << endl;
//    cout << t._top_pri_mid_pri_protect_data << endl;
    cout << t._top_pri_mid_pri_public_data << endl;
//    MidProtect *mp = &t;
//    Base *b = &t;
}

int main() {

    base_test();
    mid_public_test();
    mid_protected_test();
    mid_private_test();
    top_pub_mid_pub_test();
    top_pro_mid_pub_test();
    top_pri_mid_pub_test();
    top_pub_mid_pro_test();

    return 0;
}

