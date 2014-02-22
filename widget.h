#include"common.h"


class button: public Gtk::Button
{
  public:
    button();
    virtual ~button() = default;
    void set_name_button(std::string);
 
  protected:
    void on_button_clicked();
 };



class entry: public Gtk::Entry
{
public:
	entry();
	virtual ~entry() = default;
	
protected:
	void on_button_close();	
};



struct rowpack
{
public:
	rowpack();
	~rowpack()= default;
	void intialize(std::vector<std::string>& );

	button 				  		m_one;
	Gtk::Separator   s_one {Gtk::ORIENTATION_VERTICAL};
	button 				  	  m_two;
	Gtk::Separator   s_two {Gtk::ORIENTATION_VERTICAL};
	button 				  	  m_three;
	Gtk::Separator   s_three {Gtk::ORIENTATION_VERTICAL};
	button 				  	  m_four;
	Gtk::Separator   s_four {Gtk::ORIENTATION_VERTICAL};
	button 				 	  m_five;
	Gtk::Separator   s_five {Gtk::ORIENTATION_VERTICAL};
	button 				 	  m_six;
	
	// main container object to hold all above objects of a row
	Gtk::Box	 		row_object;
};





class calculator : public Gtk::Window
{
public:
	calculator();
	virtual ~calculator()= default;
	void run(void);
		
private:
	// the main container objects to hold all above rowpack objects into a column
	Gtk::Box    			column_object {Gtk::ORIENTATION_VERTICAL};
	
	entry					displ_area;
	Gtk::Separator     displ_sep;
	
	rowpack    			first_robject;
	Gtk::Separator		first_sep;
	
	rowpack	 			second_robject;
	Gtk::Separator		second_sep;
	
	rowpack	 			third_robject;
	Gtk::Separator		third_sep;
	
	rowpack	 			fourth_robject;
	
};

