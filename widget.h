#include"common.h"

class director
{
public:
	virtual ~director() = default;

   // virtual void ShowDialog();
	virtual void WidgetChanged(Gtk::Widget*) = 0;
	virtual void GetWidgets(Gtk::Widget*) = 0;
protected:
	director() {}
};


class Updatedirector: public director
{
public:
	Updatedirector() = default;
	virtual ~Updatedirector() = default;

	virtual void WidgetChanged(Gtk::Widget*);
	virtual void GetWidgets(Gtk::Widget* );
private:
	std::vector<Gtk::Widget*> _widgetcolletion;
};






class button: public Gtk::Button
{
  public:
    button();
    virtual ~button() = default;
    void set_name_button(std::string);
	 void set_director(director*); 
  protected:
    void on_button_clicked();
  private:
	 director* _director{nullptr};
 };



class entry: public Gtk::Entry
{
public:
	entry();
	virtual ~entry() = default;
	void set_name_entry(std::string);
	void set_director(director*);
protected:
	void on_button_close();
private:
	director* _director{nullptr};	
};




class rowpack
{
public:
	rowpack();
	~rowpack()= default;
	void intialize(std::vector<std::string>&,director*);

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
	virtual ~calculator();
	void run(void);

private:
	// the main container objects to hold all above rowpack objects into a column
	Gtk::Box    		column_object {Gtk::ORIENTATION_VERTICAL};
	
	entry					displ_area;
	Gtk::Separator    displ_sep;
	
	rowpack    			first_robject;
	Gtk::Separator		first_sep;
	
	rowpack	 			second_robject;
	Gtk::Separator		second_sep;
	
	rowpack	 			third_robject;
	Gtk::Separator		third_sep;
	
	rowpack	 			fourth_robject;

	director*         gdirector;
};


