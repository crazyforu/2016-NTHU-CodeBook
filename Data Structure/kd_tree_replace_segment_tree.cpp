/*kd��N�������u�q��*/
struct node{
	node *l,*r;
	point pid,mi,ma;
	int s;
	int data;
	node(const point &p,int d):l(0),r(0),pid(p),mi(p),ma(p),s(1),data(d),dmin(d),dmax(d){}
	inline void up(){
		mi=ma=pid;
		s=1;
		if(l){
			for(int i=0;i<kd;++i){
				mi.d[i]=min(mi.d[i],l->mi.d[i]);
				ma.d[i]=max(ma.d[i],l->ma.d[i]);
			}
			s+=l->s;
		}
		if(r){
			for(int i=0;i<kd;++i){
				mi.d[i]=min(mi.d[i],r->mi.d[i]);
				ma.d[i]=max(ma.d[i],r->ma.d[i]);
			}
			s+=r->s;
		}
	}
	inline void up2(){
		//��L�i�k�аO�V�W��s 
	}
	inline void down(){
		//��L�i�k�аO�U�� 
	}
}*root;

/*�ˬd�϶��]�t�Ϊ����*/
inline bool range_include(node *o,const point &L,const point &R){
	for(int i=0;i<kd;++i){ 
		if(L.d[i]>o->ma.d[i]||R.d[i]<o->mi.d[i])return 0;
	}//�u�n(L,R)�϶����Mo���϶����涰�N�^��true
	return 1;
}
inline bool range_in_range(node *o,const point &L,const point &R){
	for(int i=0;i<kd;++i){
		if(L.d[i]>o->mi.d[i]||o->ma.d[i]>R.d[i])return 0;
	}//�p�G(L,R)�϶������]�to���϶��N�^��true
	return 1;
}
inline bool point_in_range(node *o,const point &L,const point &R){
	for(int i=0;i<kd;++i){
		if(L.d[i]>o->pid.d[i]||R.d[i]<o->pid.d[i])return 0;
	}//�p�G(L,R)�϶������]�to->pid�o���I�N�^��true
	return 1;
}

/*���I�ק�A�H���I��Ȭ���*/
void update(node *u,const point &x,int data,int k=0){
	if(!u)return;
	u->down();
	if(u->pid==x){
		u->data=data;
		u->up2();
		return;
	}
	cmp.sort_id=k;
	update(cmp(x,u->pid)?u->l:u->r,x,data,(k+1)%kd);
	u->up2();
}

/*�϶��ק�*/ 
void update(node *o,const point &L,const point &R,int data){
	if(!o)return;
	o->down();
	if(range_in_range(o,L,R)){
		//�϶��i�k�аO�ק� 
		o->down();
		return;
	}
	if(point_in_range(o,L,R)){
		//�o���I�b(L,R)�϶��A���O�L�����k�l�𤣤@�w�b�϶���
		//���I�i�k�аO�ק� 
	}
	if(o->l&&range_include(o->l,L,R))update(o->l,L,R,data);
	if(o->r&&range_include(o->r,L,R))update(o->r,L,R,data);
	o->up2();
}

/*�϶��d�ߡA�H�`�M����*/ 
int query(node *o,const point &L,const point &R){
	if(!o)return 0;
	o->down();
	if(range_in_range(o,L,R))return o->sum;
	int ans=0;
	if(point_in_range(o,L,R))ans+=o->data;
	if(o->l&&range_include(o->l,L,R))ans+=query(o->l,L,R);
	if(o->r&&range_include(o->r,L,R))ans+=query(o->r,L,R);
	return ans;
}
