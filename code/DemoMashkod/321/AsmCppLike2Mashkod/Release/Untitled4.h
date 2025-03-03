TNode:{
  name:string,
  arr:vector<TNode>,
  next:int
}

TNode:{
  name:string,
  parent:int,
  arr:vector<TNode>,
  next:int
}

TNode:{
  id:int,
  name:string,
  parent:int,
  arr:vector<TNode>,
  next:int
}

TNode:{
  Self:TSelfPtr<TNode>,
  name:string,
  arr:vector<TNode>,
  next:TWeakPtr<TNode>
}


TNode:{
  Self:TSelfPtr<TNode>,
  Parent:TWeakPtr<TNode>,
  name:string,
  arr:vector<TNode>,
  next:TWeakPtr<TNode>
}