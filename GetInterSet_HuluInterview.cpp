struct Interval{
    int l,r;
    };

vector<Interval> get_interset(vector<Interval> d1, vector<Interval> d2){
	vector<Interval> res;

	int len1 = d1.size(),
		len2 = d2.size();
	int p1 = 0, p2 = 0;

	while(p1<len1 && p2< len2){

		int left = max(d1[p1].l, d2[p2].l),
			right = min(d1[p1].r, d2[p2].r);

		if(left<right){
			Interval now;
			now.l = left;
			now.r = right;
			res.push_back(now);

			if(d1[p1].l<d2[p2].l){
				if(d1[p1].r<d2[p2].r){
					p1++;
				}
				else{
					p2++;
				}
			}
			else if(d2[p2].r<d1[p2].r){
				p2++;
			}
			else{
				p1++;
			}
		}
		else{
			if(d1[p1].l<d2[p2].l){
				p1++;
			}
			else{
				p2++;
			}
		}

	}
	return res;
}


vector<Interval> get_interset(vector<Interval> d1, vector<Interval> d2){
	vector<Interval> res;

	int len1 = d1.size(),
		len2 = d2.size();
	int p1 = 0, p2 = 0;

	while(p1<len1 && p2< len2){

		int left = max(d1[p1].l, d2[p2].l),
			right = min(d1[p1].r, d2[p2].r);

		if(left<right){
			Interval now;
			now.l = left;
			now.r = right;
			res.push_back(now);
		}

		if(d1[p1].l<d2[p2].l){
			if(d1[p1].r<d2[p2].r){
				p1++;
			}
			else{
				p2++;
			}
		}
		else if(d2[p2].r<d1[p2].r){
			p2++;
		}
	}
}