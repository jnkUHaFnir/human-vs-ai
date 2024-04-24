    struct small {
        int a, b, c;
        small (int a, int b, int c) :a(a),b(b),c(c){}
    };
    struct big {
        int lump[1000];
    };
    
    int main (void)
    {
        Message msg1 (MessageID::WorldPeace, new small(1,2,3));
        Message msg2 (MessageID::Armaggedon, new big());
        
        msg1.status("msg1 basic");
        msg1.grow (64);
        msg1.status("msg1 grow 64");
        msg1.grow (65);
        msg1.status("msg1 grow 65");
        msg2.status("msg2");
    }