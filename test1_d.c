// #define template(fn_name, TYPE, x, y )          \
//   TYPE fn_name( TYPE x, TYPE y ) \
//   {                                  \
//     return (x > y) ? x : y;          \
//   }

#include "test1_d.h"
// GENERIC_MAX(int)

// template(typename t1,..., fn_name)
// t1 fn_name()


// template(max, typdef typename t1, t2)
// t1 max(t2 a, t2 b)
// {
    
// }
// Vector(int_v, int)
// Vector(double_v, double)
// LIST(int_l, int)


LIST(double_l, double)
LIST(int_l, int)
LIST(char_l, char)
LIST(float_l, float)


STACK(int_s, int)
// STACK(char_s, char)
// STACK(float_s, float)
// STACK(double_s, double)


QUEUE(int_q, int)
// QUEUE(char_q, char)
// QUEUE(float_q, float)
// QUEUE(double_q, double)

VECTOR(int_v, int)
MAP(int_int_m, int, int)
MAP(double_int_m, double, int)

int is_odd(int key)
{
    return ((int)key%2==1);
}


int main()
{
    
    //checking operations on generic list container

    double_l l1;
    init_list(double, l1);
    l1.insert_at_beg(&l1, 7.34);
    l1.insert_at_end(&l1, 6.2334);
    l1.insert_at_end(&l1, 6.2334);
    l1.insert_at_end(&l1, 6.2334);
    l1.insert_at_end(&l1, 6.2334);
    l1.insert_at_beg(&l1, 1.254);
    l1.disp_list(&l1);
    l1.delete_key(&l1, 7.34);
    l1.disp_list(&l1);
    l1.insert_at_end(&l1,5.67);
    l1.insert_at_end(&l1,6.435);
    l1.insert_at_end(&l1,7.764);

    double_l_iterator it_l_d;
    init_list_iterator(double, l1, it_l_d);
    double min_l;
    int flag;
    double_l_iterator it_l_d_e = *(l1.end(&l1));
    min(it_l_d, it_l_d_e ,min_l,flag);
    if(flag==1)
    {
        printf("MIN: %lf\n\n",min_l);
    }

    double_l_iterator it2_l_d;
    init_list_iterator(double, l1, it2_l_d);
    double max_l;
    int flag2;
    max(it2_l_d,it_l_d_e,max_l,flag2);
    if(flag2==1)
    {
        printf("MAX: %lf\n\n",max_l);
    }

    double_l_iterator it3_l_d;
    init_list_iterator(double, l1, it3_l_d);
    double acc_l = 0;
    accumulate(it3_l_d,it_l_d_e,acc_l);
    printf("ACC: %lf\n\n",acc_l);
    
    double_l_iterator it4_l_d = *(l1.begin(&l1));
    double_l_iterator it5_l_d = *(l1.end(&l1));


    // init_list_iterator(double, l1, it3_l_d);
    // init_list_iterator(double, l1, it4_l_d);
    find(it4_l_d, it5_l_d, 6.2334)
    if(it4_l_d.inequality(&it4_l_d, &it5_l_d))
    {
        printf("adsdas FOUND: %f\n", it4_l_d.get_value(&it4_l_d));
    }
    else
    {
        printf("asdddd Not Found\n");
    }
    
    find(it4_l_d, it5_l_d, 6.34123)
    init_list_iterator(double, l1, it3_l_d);
    if(it4_l_d.inequality(&it4_l_d, &it5_l_d))
    {
        printf("adsdas FOUND: %f\n", it4_l_d.get_value(&it4_l_d));
    }
    else
    {
        printf("asdddd Not Found\n");
    }

    double_l_iterator it6_l_d = *(l1.begin(&l1));
    it6_l_d.advance(&it6_l_d,2);

    double_l_iterator it7_l_d = *(l1.begin(&l1));
    it7_l_d.advance(&it7_l_d,6);

    find(it6_l_d, it7_l_d, 5.67)
    if(it6_l_d.inequality(&it6_l_d, &it7_l_d))
    {
        printf("advance FOUND: %f\n", it6_l_d.get_value(&it6_l_d));
    }
    else
    {
        printf("advance Not Found\n");
    }
    

    // printf("Testing iterator\n\n");
    // double_l_iterator it;
    // init_list_iterator(double, l1, it);
    // while(it.has_next(&it))
    // {
    //     printf("iterator : %f\n", it.next(&it));
    // }
    // find(it, 6.435);
    // if(it.has_next(&it))
    //     printf("SADFASDASDASDIterator: %f", it.get_value(&it));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND");
    // init_list_iterator(double, l1, it);
    // find(it, 123.4);
    // if(it.has_next(&it))
    //     printf("SADFASDASDASDIterator: %f", it.get_value(&it));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND\n");

    // init_list_iterator(double, l1, it);
    // int count = 0;
    // count(it, 6.2, count);
    // printf("Count: %d\n", count);
    // init_list_iterator(double, l1, it);
    // count_if(it, is_odd, count);
    // printf("Count: %d\n", count);



    // int_l l2;
    // init_list(int, l2);
    // l2.insert_at_end(&l2,5);
    // l2.insert_at_end(&l2,3);
    // l2.insert_at_end(&l2,7);
    // disp_list_int(&l2);
    // l2.insert_at_beg(&l2, 5);
    // l2.insert_at_end(&l2, 3);
    // l2.insert_at_beg(&l2, 7);
    // l2.disp_list(&l2);
    // l2.delete_key(&l2, 8);
    // l2.disp_list(&l2);

    // printf("Testing iterator\n\n");
    // int_l_iterator it;
    // init_list_iterator(int, l2, it);
    // // while(it.has_next(&it))
    // // {
    // //     printf("iterator : %f\n", it.next(&it));
    // // }
    // find_if(it, is_odd);
    // if(it.has_next(&it))
    //     printf("SADFASDASDASDIterator: %d\n", it.get_value(&it));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND\n");
    // if(it.has_next(&it))it.next(&it);
    // find_if(it, is_odd);
    // if(it.has_next(&it))
    //     printf("SADFASDASDASDIterator: %d\n", it.get_value(&it));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND\n");

    // char_l l3;
    // init_list(char, l3);
    // l3.insert_at_beg(&l3,'A');
    // l3.insert_at_beg(&l3,'B');
    // l3.disp_list(&l3);

    // float_l l4;
    // init_list(float, l4);
    // l4.insert_at_end(&l4,12.4323f);
    // l4.insert_at_beg(&l4,3.14f);
    // l4.disp_list(&l4);


    //checking operations on generic stack container
    
    // int_s s1;
    // init_stack(int, s1);
    // s1.push(&s1,4);
    // s1.push(&s1,1);
    // s1.push(&s1,9);
    // s1.push(&s1,5);
    // s1.push(&s1,8);
    // s1.push(&s1,3);
    // s1.push(&s1,34);
    // s1.push(&s1,2);
    // s1.disp_stack(&s1);
    // s1.pop(&s1);
    // s1.disp_stack(&s1);
    // printf("PEEK - %d\n\n",s1.peek_stack(&s1));


    // int_s_iterator it3_s_d;
    // init_list_iterator(int, s1, it3_s_d);
    // int acc_s = 0;
    // accumulate(it3_s_d,acc_s);
    // printf("ACC: %d\n\n",acc_s);
    
    // int_s_iterator it4_s_d = *(s1.begin(&s1));
    // int_s_iterator it5_s_d = *(s1.end(&s1));


    // // init_list_iterator(int, s1, it3_s_d);
    // // init_list_iterator(int, s1, it4_s_d);
    // find(it4_s_d, it5_s_d, 9)
    // if(it4_s_d.inequality(&it4_s_d, &it5_s_d))
    // {
    //     printf("adsdas FOUND: %d\n", it4_s_d.get_value(&it4_s_d));
    // }
    // else
    // {
    //     printf("asdddd Not Found\n");
    // }
    
    // find(it4_s_d, it5_s_d, 67657)
    // init_list_iterator(int, s1, it3_s_d);
    // if(it4_s_d.inequality(&it4_s_d, &it5_s_d))
    // {
    //     printf("adsdas FOUND: %d\n", it4_s_d.get_value(&it4_s_d));
    // }
    // else
    // {
    //     printf("asdddd Not Found\n");
    // }

    // int_s_iterator it6_s_d = *(s1.begin(&s1));
    // it6_s_d.advance(&it6_s_d,2);

    // int_s_iterator it7_s_d = *(s1.begin(&s1));
    // it7_s_d.advance(&it7_s_d,6);

    // find(it6_s_d, it7_s_d, 5)
    // if(it6_s_d.inequality(&it6_s_d, &it7_s_d))
    // {
    //     printf("advance FOUND: %d\n", it6_s_d.get_value(&it6_s_d));
    // }
    // else
    // {
    //     printf("advance Not Found\n");
    // }

    // printf("Testing iterator\n\n");
    // int_l_iterator it;
    // init_stack_iterator(int, s1, it);
    // while(it.has_next(&it))
    // {
    //     printf("iterator : %f\n", it.next(&it));
    // }
    // find(it, 4);
    // if(it.has_next(&it))
    //     printf("Iterator: %d\n", it.get_value(&it));
    // else
    //     printf("Iterator: NOT FOUND\n");
    // find_if(it, is_odd);
    // if(it.has_next(&it))
    //     printf("Iterator: %d\n", it.get_value(&it));
    // else
    //     printf("Iterator: NOT FOUND\n");
    // if(it.has_next(&it))it.next(&it);
    // find_if(it, is_odd);
    // if(it.has_next(&it))
    //     printf("SADFASDASDASDIterator: %d\n", it.get_value(&it));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND\n");

    // char_s s2;
    // init_stack(char, s2);
    // s2.push(&s2,'A');
    // s2.push(&s2,'L');
    // s2.disp_stack(&s2);
    // s2.pop(&s2);
    // s2.pop(&s2);
    // s2.pop(&s2);
    // s2.disp_stack(&s2);
    // printf("PEEK - %c\n\n",s2.peek_stack(&s2));

    // float_s s3;
    // init_stack(float, s3);
    // s3.pop(&s3);
    // s3.push(&s3, 3.14f);
    // s3.disp_stack(&s3);
    // printf("PEEK - %f\n\n",s3.peek_stack(&s3));

    // double_s s4;
    // init_stack(double, s4);
    // s4.push(&s4,12.43234);
    // s4.push(&s4,1141.3435);
    // s4.disp_stack(&s4);
    // s4.pop(&s4);
    // s4.disp_stack(&s4);
    // printf("PEEK - %lf\n\n",s4.peek_stack(&s4));


    //checking operations on generic queue container

    // int_q q1;
    // init_queue(int, q1);
    // q1.enqueue(&q1,3);
    // q1.enqueue(&q1,7);
    // q1.enqueue(&q1,2);
    // q1.enqueue(&q1,5);
    // q1.enqueue(&q1,3);
    // q1.enqueue(&q1,4);
    // q1.enqueue(&q1,9);
    // q1.enqueue(&q1,9);
    // q1.enqueue(&q1,54);
    // q1.enqueue(&q1,32);
    // q1.enqueue(&q1,13);
    // q1.disp_queue(&q1);
    // q1.dequeue(&q1);
    // q1.dequeue(&q1);
    // q1.disp_queue(&q1);
    // printf("PEEK - %d\n\n",q1.peek_queue(&q1));




    // int_q_iterator it3_q_d;
    // init_queue_iterator(int, q1, it3_q_d);
    // int acc_s = 0;
    // accumulate(it3_q_d,acc_s);
    // printf("ACC: %d\n\n",acc_s);
    
    // int_q_iterator it4_q_d = *(q1.begin(&q1));
    // int_q_iterator it5_q_d = *(q1.end(&q1));


    // // init_queue_iterator(int, q1, it3_q_d);
    // // init_queue_iterator(int, q1, it4_q_d);
    // find(it4_q_d, it5_q_d, 9)
    // if(it4_q_d.inequality(&it4_q_d, &it5_q_d))
    // {
    //     printf("adsdas FOUND: %d\n", it4_q_d.get_value(&it4_q_d));
    // }
    // else
    // {
    //     printf("asdddd Not Found\n");
    // }
    
    // find(it4_q_d, it5_q_d, 67657)
    // init_queue_iterator(int, q1, it3_q_d);
    // if(it4_q_d.inequality(&it4_q_d, &it5_q_d))
    // {
    //     printf("adsdas FOUND: %d\n", it4_q_d.get_value(&it4_q_d));
    // }
    // else
    // {
    //     printf("asdddd Not Found\n");
    // }

    // int_q_iterator it6_q_d = *(q1.begin(&q1));
    // it6_q_d.advance(&it6_q_d,2);

    // int_q_iterator it7_q_d = *(q1.begin(&q1));
    // it7_q_d.advance(&it7_q_d,6);

    // find(it6_q_d, it7_q_d, 9)
    // if(it6_q_d.inequality(&it6_q_d, &it7_q_d))
    // {
    //     printf("advance FOUND: %d\n", it6_q_d.get_value(&it6_q_d));
    // }
    // else
    // {
    //     printf("advance Not Found\n");
    // }



    // printf("Testing iterator\n\n");
    // int_q_iterator it;
    // init_queue_iterator(int, q1, it);
    // while(it.has_next(&it))
    // {
    //     printf("iterator : %d\n", it.next(&it));
    // }
    // find(it, 2);
    // if(it.has_next(&it))
    //     printf("Iterator: %d\n", it.get_value(&it));
    // else
    //     printf("Iterator: NOT FOUND\n");
    // find_if(it, is_odd);
    // if(it.has_next(&it))
    //     printf("Iterator: %d\n", it.get_value(&it));
    // else
    //     printf("Iterator: NOT FOUND\n");
    // if(it.has_next(&it))it.next(&it);
    // find_if(it, is_odd);
    // if(it.has_next(&it))
    //     printf("SADFASDASDASDIterator: %d\n", it.get_value(&it));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND\n");



    // char_q q2;
    // init_queue(char, q2);
    // q2.enqueue(&q2,'Q');
    // q2.disp_queue(&q2);
    // q2.dequeue(&q2);
    // q2.disp_queue(&q2);
    // printf("PEEK - %c\n\n",q2.peek_queue(&q2));

    // float_q q3;
    // init_queue(float, q3);
    // q3.dequeue(&q3);
    // q3.disp_queue(&q3);
    // q3.enqueue(&q3, 4524.34f);
    // q3.enqueue(&q3, 12.43234f);
    // q3.disp_queue(&q3);
    // printf("PEEK - %f\n\n",q3.peek_queue(&q3));

    // double_q q4;
    // init_queue(double, q4);
    // q4.enqueue(&q4,12.43);
    // q4.enqueue(&q4,234.536);
    // q4.disp_queue(&q4);
    // printf("PEEK - %lf\n\n",q4.peek_queue(&q4));

    //checking operations on generic vector

    int_v v;
    printf("HERE");
    init_vector(int, v);
    v.make_new_dynamic_table(&v, 10);
    v.push_back(&v, 5);
    v.push_back(&v, 7);
    v.push_back(&v, 4);
    v.push_back(&v, 5);
    v.push_back(&v, 2);
    v.push_back(&v, 9);
    v.push_back(&v, 6);
    v.push_back(&v, 8);
    v.push_back(&v, 7);
    v.push_back(&v, 8);
    v.push_back(&v, 9);
    printf("HERE");
    for (int i = 0; i < v.dt->cur_size; i++)
    {
        printf("%d\n", v.access(&v, i));
    }
    v.pop_back(&v);
    for (int i = 0; i < v.dt->cur_size; i++)
    {
        printf("%d\n", v.access(&v, i));
    }
    // v.my_free(&v);





    int_v_iterator it3_v_d;
    init_vector_iterator(int, v, it3_v_d);
    
    int_v_iterator it4_v_d = *(v.begin(&v));
    int_v_iterator it5_v_d = *(v.end(&v));

    int acc_s = 0;
    accumulate(it4_v_d, it5_v_d, acc_s);
    printf("ACC: %d\n\n",acc_s);

    it4_v_d = *(v.begin(&v));

    // init_vector_iterator(int, v, it3_v_d);
    // init_vector_iterator(int, v, it4_v_d);
    find(it4_v_d, it5_v_d, 9)
    if(it4_v_d.inequality(&it4_v_d, &it5_v_d))
    {
        printf("adsdas FOUND: %d\n", it4_v_d.get_value(&it4_v_d));
    }
    else
    {
        printf("asdddd Not Found\n");
    }
    
    find(it4_v_d, it5_v_d, 67657)
    init_vector_iterator(int, v, it3_v_d);
    if(it4_v_d.inequality(&it4_v_d, &it5_v_d))
    {
        printf("adsdas FOUND: %d\n", it4_v_d.get_value(&it4_v_d));
    }
    else
    {
        printf("asdddd Not Found\n");
    }

    int_v_iterator it6_v_d = *(v.begin(&v));
    it6_v_d.advance(&it6_v_d,2);

    int_v_iterator it7_v_d = *(v.begin(&v));
    it7_v_d.advance(&it7_v_d,6);

    find(it6_v_d, it7_v_d, 5)
    if(it6_v_d.inequality(&it6_v_d, &it7_v_d))
    {
        printf("advance FOUND: %d\n", it6_v_d.get_value(&it6_v_d));
    }
    else
    {
        printf("advance Not Found\n");
    }

    v.display(&v);

    // printf("Testing iterator\n\n");
    // int_v_iterator it2;
    // init_vector_iterator(int, v, it2);
    // while(it.has_next(&it))
    // {
    //     printf("iterator : %d\n", it.next(&it));
    // }
    // find(it2, 4);
    // if(it2.has_next(&it2))
    //     printf("Iterator: %d\n", it2.get_value(&it2));
    // else
    //     printf("Iterator: NOT FOUND\n");
    // find_if(it2, is_odd);
    // if(it2.has_next(&it2))
    //     printf("Iterator: %d\n", it2.get_value(&it2));
    // else
    //     printf("Iterator: NOT FOUND\n");
    // if(it2.has_next(&it2))it2.next(&it2);
    // find_if(it2, is_odd);
    // if(it2.has_next(&it2))
    //     printf("SADFASDASDASDIterator: %d\n", it2.get_value(&it2));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND\n");


    //checking operations on map container

    int_int_m m1;
    init_map(int, int, 100, m1);
    m1.insert_map(&m1, 5, 10);
    m1.insert_map(&m1, 7, 14);
    m1.insert_map(&m1, 9, 18);
    m1.insert_map(&m1, 6, 12);
    m1.insert_map(&m1, 25, 50);
    m1.insert_map(&m1, 9, 231);
    m1.delete_map(&m1, 12415);
    
    int check, v1;
    v1 = m1.retrieve_map(&m1, 9, &check);
    if(check)
    {
        printf("R: %d\n", v1);
    }
    else
    {
        printf("Nothing to retreive\n");
    }


    int_int_m_iterator it3_m_d;
    init_map_iterator(int, int, m1, it3_m_d);
    
    
    int_int_m_iterator it4_m_d = *(m1.begin(&m1));
    int_int_m_iterator it5_m_d = *(m1.end(&m1));

    int acc_q = 0;
    accumulate(it4_m_d, it5_m_d ,acc_q);
    printf("ACC: %d\n\n",acc_q);

    it4_m_d = *(m1.begin(&m1));

    // init_map_iterator(int, int, m1, it3_m_d);
    // init_map_iterator(int, int, m1, it4_m_d);
    find(it4_m_d, it5_m_d, 7)
    if(it4_m_d.inequality(&it4_m_d, &it5_m_d))
    {
        printf("adsdas FOUND: %d\n", it4_m_d.get_value(&it4_m_d));
    }
    else
    {
        printf("asdddd Not Found\n");
    }
    
    find(it4_m_d, it5_m_d, 67657);
    init_map_iterator(int, int, m1, it3_m_d);
    if(it4_m_d.inequality(&it4_m_d, &it5_m_d))
    {
        printf("adsdas FOUND: %d\n", it4_m_d.get_value(&it4_m_d));
    }
    else
    {
        printf("asdddd Not Found\n");
    }

    int_int_m_iterator it6_m_d = *(m1.begin(&m1));
    it6_m_d.advance(&it6_m_d,2);

    int_int_m_iterator it7_m_d = *(m1.begin(&m1));
    it7_m_d.advance(&it7_m_d,6);

    find(it6_m_d, it7_m_d, 6)
    if(it6_m_d.inequality(&it6_m_d, &it7_m_d))
    {
        printf("advance FOUND: %d\n", it6_m_d.get_value(&it6_m_d));
    }
    else
    {
        printf("advance Not Found\n");
    }

    int_int_m_iterator it2;
    init_map_iterator(int, int, m1, it2);
    while(it2.has_next(&it2))
    {
        printf("Iterator: %d %d\n", it2.get_value(&it2), m1.retrieve_map(&m1, it2.next(&it2), &check));
    }

    m1.disp_map(&m1);
    // init_map_iterator(int, int, m1, it2);
    // find(it2, 9);
    // if(it2.has_next(&it2))
    //     printf("SADFASDASDASDIterator: %d", it2.get_value(&it2));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND");
    // init_map_iterator(int, int, m1, it2);
    // find(it2, 324423);
    // if(it2.has_next(&it2))
    //     printf("SADFASDASDASDIterator: %d", it2.get_value(&it2));
    // else
    //     printf("SADFASDASDASDIterator: NOT FOUND\n");

    // init_map_iterator(int, int, m1, it2);
    // int count = 0;
    // count(it2, 4, count);
    // printf("Count: %d\n", count);
    // init_map_iterator(int, int, m1, it2);
    // count_if(it2, is_odd, count);
    // printf("Count: %d\n", count);
    // int_l l2;





    // double_int_m m2;
    // init_map(double, int, 100, m2);
    // m2.insert_map(&m2, 5.435, 10);
    // m2.insert_map(&m2, 7.09, 14);
    // m2.insert_map(&m2, 9.0934, 18);
    // m2.insert_map(&m2, 6.12, 12);
    // m2.insert_map(&m2, 25.54, 50);
    // m2.insert_map(&m2, 9.32, 231);
    // m2.delete_map(&m2, 9.32);
    
    // v1 = m2.retrieve_map(&m2, 9.32, &check);
    // if(check)
    // {
    //     printf("R: %d\n", v1);
    // }
    // else
    // {
    //     printf("Nothing to retreive\n");
    // }



}