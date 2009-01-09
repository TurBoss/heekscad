// PropertyCheck.h

#if !defined PropertyCheck_HEADER
#define PropertyCheck_HEADER

#include "Property.h"

class PropertyCheck:public Property{
private:
	wxString title;

public:
	void (*m_callbackfunc)(bool, HeeksObj*); // onoff
	HeeksObj* m_object;
	bool m_initial_value;

	PropertyCheck(const wxChar* t, bool initial_value, HeeksObj* object,  void(*callbackfunc)(bool, HeeksObj*) = NULL);
	~PropertyCheck();

	// Property's virtual functions
	int get_property_type(){return CheckPropertyType;}
	bool property_editable()const{return m_callbackfunc != NULL;}
	Property *MakeACopy(void)const;
	void CallSetFunction()const{ if(m_callbackfunc)(*m_callbackfunc)(m_initial_value, m_object);}
	const wxChar* GetShortString(void)const;
};

#endif
