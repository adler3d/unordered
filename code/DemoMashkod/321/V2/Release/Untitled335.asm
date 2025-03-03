vector{string} split(string s,string needle)
{
  vector{string} arr;
  auto p=0;
  for(;;){
    auto pos=__StrFind(s,needle,p);
    if(pos<0){arr.push_back(__StrSubStr(s,p,s.size()-p));return arr;}
    arr.push_back(__StrSubStr(s,p,pos-p));
    p=pos+needle.size();
  }
  return arr;
}

vector{int} load(string s){
  return load(split(s," "));
}

vector{int} load(vector{string} arr){
  vector{int} out;
  for(int i=0;i<arr.size();i++)out.push_back(__SToI(arr[i]));
  return out;
}

vector{int} clean(vector{int} arr){
  vector{int} out;
  for(int i=0;i<arr.size();i++)if(arr[i]>0)out.push_back(arr[i]);
  return out;
}

struct t_load_from_string_inp{
  t_heap heap;
  t_vector_char s;
}

struct t_split_out{
  t_heap heap;
  t_vector_string arr;
}

t_load_from_arr_out load_string(t_load_from_string_inp inp){
  t_heap heap=inp.heap;
  t_vector_char s=inp.s;
  t_vector_char needle=" ";
  t_load_inp next;
  {
    t_split_inp split_inp;
    split_inp.heap=heap;
    split_inp.needle=needle;
    auto split_out=split(split_inp);
    heap=split.heap;
    next.heap=heap;
    next.arr=split_out.arr;
  }
  auto result=load_from_arr(next);
  return result;
}

struct t_load_from_arr_out{
  t_heap heap;
  t_vector_int arr;
}

struct t_load_from_arr_inp{
  t_heap heap;
  t_vector_vector_char arr;
}

t_load_from_arr_out load_from_arr(t_load_from_arr_inp inp){
  auto heap=inp.heap;
  auto arr=inp.arr;
  t_vector_int out;
  for(int i=0;i<arr.size;i++){
    vector_char str;
    {
      t_vector_vector_char_at_inp vvcai;
      inp.heap=heap;
      inp.arr=arr;
      inp.i=i;
      str=t_vector_vector_char_at(heap,arr,i);
    }
    t_raw_string raw_string;
    t_vector_char_to_raw_string_inp vctrsi;
    {
      vctrsi.heap=heap;
      vctrsi.str=str;
      raw_string=t_vector_char_to_raw_string(vctrsi);
    }
    int value=__SToI(raw_string);
    t_vector_int_push_back_inp vipbo;
    {
      t_vector_int_push_back_inp vipbi;
      vipbi.heap=heap;
      vipbi.arr=out;
      vipbi.value=value;
      vipbo=t_vector_int_push_back(vvcpbi);
    }
    heap=vipbo.heap;
    out=vipbo.arr;
  }
  t_load_from_arr_out result;
  result.heap=heap;
  result.arr=out;
  return result;
} - ����.

t_load_from_arr_out load_from_arr(t_heap heap,vector{vector{char}} arr){
  vector{int} out;
  for(int i=0;i<arr.size;i++){
    //auto str=arr[heap,i];
    vector{char} str=arr.at(heap,i);
    string blob=str.toBlob(heap);
    int value=__SToI(blob);
    t_vector_int_push_back_inp vipbo;
    vipbo=out.push_back(heap,value);
    heap=vipbo.heap;
    out=vipbo.arr;
  }
  t_load_from_arr_out result;
  result.heap=heap;
  result.arr=out;
  return result;
} - �����.

{t_heap,vector{int}} load_from_arr(t_heap inp_heap,vector{vector{char}} arr){
  auto heap=inp_heap;
  vector{int} out;
  for(int i=0;i<arr.size;i++){
    //auto str=arr[heap,i];
    vector{char} str=arr.at(heap,i);
    string blob=str.toBlob(heap);
    int value=__SToI(blob);
    t_vector_int_push_back_inp vipbo;
    vipbo=out.push_back(heap,value);
    heap=vipbo.heap;
    out=vipbo.arr;
  }
  return {heap,out};
} - ����� �������.

{t_heap,vector{int}} load_from_arr(t_heap inp_heap,vector{vector{char}} arr){
  auto heap=inp_heap;
  vector{int} out;
  for(int i=0;i<arr.size;i++){
    //auto str=arr[heap,i];
    vector{char} str=arr.at(heap,i);
    string blob=str.toBlob(heap);
    int value=__SToI(blob);
    {heap,out}=out.push_back(heap,value);
  }
  return {heap,out};
} - ������ � ������.

auto load_from_arr=[heap](vector{vector{char}} arr)->vector{int}{
  vector{int} out;
  for(int i=0;i<arr.size;i++){
    vector{char} str=arr[i];
    string blob=str.toBlob();
    int value=__SToI(blob);
    out=out.push_back(value);
  }
  return out;
} - �����.

template{t_heap heap}{}{}
vector{int} load_from_arr(vector{vector{char}} arr){
  vector{int} out;
  for(int i=0;i<arr.size;i++){
    vector{char} str=arr[i];
    string blob=str.toBlob();
    int value=__SToI(blob);
    out=out.push_back(value);
  }
  return out;
} - �����. ������� �������� heap`� � ������ ����������� ������������ ������.



-----
-
-
-
-
-----

���... string ����������� �� vector{char} ���, ��� ��� ������ ���������� � ���, ��� ������ �� ���������� ����.
������ � vector{string} ������������ ������ ������ ������ ���� ������ ������������� ������� ����.
����� � ���� ������ ������ ���� ������. ��� ���� �� �����.
��� ��� �����������.
� ���� �������� �����������, �� ����� ������ ���� ������ �� ��� ������, � ����� �������� � �����.
���. � ������ ����������� ����� ����������� �� �����.
��� ������� ������ ��� ������. ��� ����������� ������� ������ ������ ������������� ������� �� ����� �� �������������� �������.
�����, � ���� ������� ������ ������ ���������� � ��������, �� ����� ����������� � ����������������� ����� ������ ��������?
������ ��.

t_heap mod(t_heap heap){
  vector{char} arr;
  arr.resize(heap,2);
  heap=arr.set(heap,0,'1');
  return heap; //������ ��������. � ���� �������� ��, ��� ����� �� ����� �����������.
}

��������� � ���, ��� ���� � �� ��� � ��� ��������� ����� �� ������� � �� ����� �� ���������� ���������.
������������ ���-�� ��������� ���� ������ � �� �������. � ������� ������ ������.
� ���� ������ ��� �������� �� ��� ������.
��������������������������!!!!!!!!!!!!!!
�� � ����� ����� �����? ��������� �����������?
������� ��������������� ���� ��� ������ ���������� ����.
��� ������ ���������� ����������� �������.
��� ������ ���������� �� ����������� �������.
�� ��� ����� ������ ������ ����������� �������, ���� �� ������� ������ ��� �� ���������?


{t_heap,vector{string}} split(t_heap heap,string s,string needle)
{
  vector{string} arr;
  auto p=0;
  for(;;){
    auto pos=__StrFind(s,needle,p);
    if(pos<0){arr.push_back(__StrSubStr(s,p,s.size()-p));return arr;}
    arr.push_back(__StrSubStr(s,p,pos-p));
    p=pos+needle.size();
  }
  return arr;
}


void foo(){
  string s="1"; //� ������ ����������� ��������� ����.
  s+="2"; //������������ ������� ������ ���� ������� ������. ��������� �������� � ������ ����.
}

void foo(){
  string s="1"; //� ���� ������ ��������� ����� ������. ����� � �������� ����������� � �. ����� ������ ���������� �� ����.
  s+="2"; //������������ ������� ������ ���� ������ �����. 
  string t=s; //�������� ������ ������. ������ � ���� ����� ������.
}

���� ���� � ���, ��� ��� ��� ���������������� �������.
��� ����� ������������� � ��� � �� ����� ������ ��������.

���� ���� �� ������������, �� �������� ����� ������ ������ �� ��� ���, ���� �� ��������� �����������.












