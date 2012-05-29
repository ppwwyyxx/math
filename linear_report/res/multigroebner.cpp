namespace mU {
	namespace{
		order_q com_ptr;
		uint n;
		typedef std::pair<uint,uint> tuple2;
		typedef std::set<tuple2> tuple2set;

		bool groebner_less(const sparse_q & g, const sparse_q & h);

		void groebner_reduce(sparse_q & r, const sparse_q & f, 
				const std::vector<sparse_q> polylist);

		void groebner_reduce(std::vector<sparse_q> & polylist, uint index);

		void mono_q_lcm(mono_q & r, const mono_q & f, const mono_q & g);

		void mono_q_div(mono_q & r, const mono_q & f, const mono_q & g);

		bool mono_q_divisible(const mono_q & f, const mono_q & g);

		bool crit1(const mono_q & f, const mono_q & g);

		bool for_crit2(const mono_q & h, const mono_q & f, const mono_q & g);

		void crit2(tuple2set & NC, tuple2set & C, uint s, sparse_q & lms);

		void syl(sparse_q & r, const sparse_q & f, const sparse_q & g, 
				const mono_q & lmf, const mono_q & lmg);

		void groebner_buchberger(std::vector<sparse_q> & gb, sparse_q & lms, 
				const std::vector<sparse_q> & polylist);

		void minimal_groebner(std::vector<sparse_q> & gb, sparse_q & lms);

		void reduced_groebner(std::vector<sparse_q> & gb);
	}
	void MultiGroebnerBasisQ(std::vector<sparse_q> & gb, 
			const std::vector<sparse_q> & polylist, uint totalvar, order_q order);
}
